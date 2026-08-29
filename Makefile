.PHONY: help run build debug test check copy init new clean
.DEFAULT_GOAL := run

# Configuration
PROBLEM ?= code
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXX := g++-16
	CXXFLAGS := -Wall -Wextra -std=c++23 -O2 -pipe
else
	CXX := g++
	CXXFLAGS := -Wall -Wextra -std=c++23 -O2 -pipe -static
endif
DEBUGFLAGS := -Dlolainta -g -O0

# Colors
GREEN  := \033[32m
RED    := \033[31m
YELLOW := \033[33m
BLUE   := \033[34m
NC     := \033[0m

# Test files for current problem
PRIMARY_IN  := $(PROBLEM).in
PRIMARY_ANS := $(PROBLEM).ans
EXTRA_INS   := $(wildcard $(PROBLEM)_*.in)
TESTS       := $(PRIMARY_IN) $(EXTRA_INS)

# Output files
BIN       := $(PROBLEM)
DBG_BIN   := $(PROBLEM)_dbg
OUT_FILE  := $(PROBLEM).out
DBN_FILE  := $(PROBLEM).dbn

help:
	@echo "Usage: make [target] [PROBLEM=name]"
	@echo ""
	@echo "Targets:"
	@echo "  help        Show this help"
	@echo "  run         Build and run (default)"
	@echo "  build       Compile release binary"
	@echo "  debug       Compile with debug flags and run"
	@echo "  test        Run all tests for PROBLEM"
	@echo "  check       Run single test: make check TEST=2"
	@echo "  copy        Copy source to clipboard"
	@echo "  init NAME=x Create x.cpp from template.cpp"
	@echo "  new NAME=x  Clean + init (alias)"
	@echo "  clean       Remove build artifacts"
	@echo ""
	@echo "Examples:"
	@echo "  make                    # run code.cpp"
	@echo "  make PROBLEM=a run      # run a.cpp"
	@echo "  make PROBLEM=a test     # test a.cpp against a.in, a_*.in"
	@echo "  make PROBLEM=a copy     # copy a.cpp to clipboard"
	@echo "  make init NAME=b        # create b.cpp from template"

run: build
	@echo "$(BLUE)Running $(BIN)$(NC)"
	@./$(BIN)

build: $(BIN)

$(BIN): $(PROBLEM).cpp
	@echo "$(BLUE)Building $(BIN)...$(NC)"
	@$(CXX) $(CXXFLAGS) $< -o $@

debug: $(DBG_BIN)
	@echo "$(BLUE)Running $(DBG_BIN) with debug...$(NC)"
	@./$(DBG_BIN) < $(PRIMARY_IN) 2> $(DBN_FILE) > $(OUT_FILE) || true
	@echo "$(YELLOW)=== Input ===$(NC)"
	@cat $(PRIMARY_IN)
	@echo "$(YELLOW)=== Answer ===$(NC)"
	@cat $(OUT_FILE)
	@echo "$(YELLOW)=== Debug Output ===$(NC)"
	@cat $(DBN_FILE)

$(DBG_BIN): $(PROBLEM).cpp
	@echo "$(BLUE)Building debug $(DBG_BIN)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $< -o $@

test: build
	@if [ ! -f "$(PRIMARY_IN)" ]; then \
		echo "$(RED)No test file: $(PRIMARY_IN)$(NC)"; \
		exit 1; \
	fi
	@echo "$(BLUE)Testing $(PROBLEM)...$(NC)"
	@passed=0; failed=0; \
	for test_in in $(TESTS); do \
		base=$$(basename "$$test_in" .in); \
		out_file="$$base.out"; \
		ans_file="$$base.ans"; \
		dbn_file="$$base.dbn"; \
		echo -n "  $$base: "; \
		./$(BIN) < "$$test_in" > "$$out_file" 2> /dev/null; \
		if [ -f "$$ans_file" ]; then \
			if diff -u "$$ans_file" "$$out_file" > /dev/null; then \
				echo "$(GREEN)PASS$(NC)"; \
				passed=$$((passed + 1)); \
			else \
				echo "$(RED)FAIL$(NC)"; \
				failed=$$((failed + 1)); \
				echo "$(YELLOW)--- Expected ---$(NC)"; \
				cat "$$ans_file"; \
				echo "$(YELLOW)--- Got ---$(NC)"; \
				cat "$$out_file"; \
				echo "$(YELLOW)--- Diff ---$(NC)"; \
				diff -u "$$ans_file" "$$out_file" || true; \
				if [ -f "$$dbn_file" ]; then \
					echo "$(YELLOW)--- Debug Output ---$(NC)"; \
					cat "$$dbn_file"; \
				fi; \
			fi; \
		else \
			echo "$(YELLOW)NO ANSWER FILE$(NC)"; \
			cat "$$out_file"; \
			passed=$$((passed + 1)); \
		fi; \
	done; \
	echo ""; \
	if [ $$failed -eq 0 ]; then \
		echo "$(GREEN)All $$passed test(s) passed!$(NC)"; \
	else \
		echo "$(RED)$$failed failed, $$passed passed$(NC)"; \
		exit 1; \
	fi

check: build
	@if [ -z "$(TEST)" ]; then \
		echo "$(RED)Usage: make check TEST=N$(NC)"; \
		exit 1; \
	fi
	@test_in="$(PROBLEM)_$(TEST).in"; \
	ans_file="$(PROBLEM)_$(TEST).ans"; \
	out_file="$(PROBLEM)_$(TEST).out"; \
	dbn_file="$(PROBLEM)_$(TEST).dbn"; \
	if [ ! -f "$$test_in" ]; then \
		echo "$(RED)Test file not found: $$test_in$(NC)"; \
		exit 1; \
	fi; \
	echo "$(BLUE)Running $(PROBLEM) test $(TEST)...$(NC)"; \
	./$(BIN) < "$$test_in" > "$$out_file" 2> /dev/null; \
	if [ -f "$$ans_file" ]; then \
		if diff -u "$$ans_file" "$$out_file" > /dev/null; then \
			echo "$(GREEN)PASS$(NC)"; \
		else \
			echo "$(RED)FAIL$(NC)"; \
			echo "$(YELLOW)--- Expected ---$(NC)"; \
			cat "$$ans_file"; \
			echo "$(YELLOW)--- Got ---$(NC)"; \
			cat "$$out_file"; \
			echo "$(YELLOW)--- Diff ---$(NC)"; \
			diff -u "$$ans_file" "$$out_file" || true; \
			if [ -f "$$dbn_file" ]; then \
				echo "$(YELLOW)--- Debug Output ---$(NC)"; \
				cat "$$dbn_file"; \
			fi; \
			exit 1; \
		fi; \
	else \
		echo "$(YELLOW)NO ANSWER FILE$(NC)"; \
		cat "$$out_file"; \
	fi

copy: build
	@cat $(PROBLEM).cpp | { \
		if command -v pbcopy >/dev/null 2>&1; then pbcopy; \
		elif command -v xclip >/dev/null 2>&1; then xclip -selection clipboard; \
		elif command -v clip.exe >/dev/null 2>&1; then clip.exe; \
		elif command -v osc52 >/dev/null 2>&1; then osc52; \
		else echo "$(RED)No clipboard tool found$(NC)" >&2; exit 1; fi; \
	} && echo "$(GREEN)✓ Copied $(PROBLEM).cpp to clipboard$(NC)"

init:
	@if [ -z "$(NAME)" ]; then \
		echo "$(RED)Usage: make init NAME=x$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f template.cpp ]; then \
		echo "$(RED)template.cpp not found$(NC)"; \
		exit 1; \
	fi
	@cp template.cpp $(NAME).cpp
	@echo "$(GREEN)Created $(NAME).cpp from template.cpp$(NC)"

new: clean init

clean:
	@rm -f $(BIN) $(DBG_BIN)
	@rm -f *.out *.dbn
	@echo "$(GREEN)Cleaned$(NC)"
