# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color
BOLD = \033[1m

# Get all Cpp directories
CPP_DIRS := $(wildcard Cpp*)

# Default target
all:
	@echo "$(RED)$(YELLOW)Available commands:$(NC)"
	@echo "$(GREEN)make fclean$(NC)           - Clean all Cpp directories"
	@echo "$(GREEN)make test$(NC)             - Test all Cpp directories"
	@echo "$(GREEN)make test CppXX$(NC)       - Test specific module (e.g., Cpp07)"

# Clean target
fclean:
	@echo "$(YELLOW)Cleaning all Cpp directories...$(NC)"
	@for cpp_dir in Cpp*/; do \
		echo "$(GREEN)Entering directory: $(BLUE)$$cpp_dir$(NC)"; \
		cd "$$cpp_dir"; \
		for ex_dir in ex*/; do \
			echo "  $(GREEN)Cleaning: $(BLUE)$$ex_dir$(NC)"; \
			cd "$$ex_dir"; \
			make fclean; \
			cd ..; \
		done; \
		cd ..; \
	done

# Test target with Valgrind
test: $(wordlist 2,2,$(MAKECMDGOALS))
	@> errors.log
	@errors=0; \
	if [ "$(wordlist 2,2,$(MAKECMDGOALS))" != "" ]; then \
		echo "$(BOLD)$(PURPLE)Testing $(wordlist 2,2,$(MAKECMDGOALS))...$(NC)"; \
		cd "$(wordlist 2,2,$(MAKECMDGOALS))"; \
		for ex_dir in ex*/; do \
			echo "$(BLUE)Testing $$ex_dir...$(NC)"; \
			cd "$$ex_dir"; \
			make re > /dev/null 2>&1; \
			if [ -f prog ]; then \
				echo "$(GREEN)Running Valgrind for $${ex_dir}...$(NC)"; \
				./prog > /dev/null 2>&1; \
				echo "\n=== $(wordlist 2,2,$(MAKECMDGOALS))/$$ex_dir ===" >> ../../errors.log; \
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./prog 2>> ../../errors.log > /dev/null; \
				if [ $$? -ne 0 ]; then \
					echo "$(RED)Valgrind found errors in $${ex_dir}$(NC)"; \
					errors=1; \
				fi; \
			else \
				echo "$(RED)No executable found in $${ex_dir}$(NC)"; \
				errors=1; \
			fi; \
			cd ..; \
		done; \
		cd ..; \
	else \
		echo "$(PURPLE)Testing all Cpp directories...$(NC)"; \
		for cpp_dir in $(CPP_DIRS); do \
			echo "$(BLUE)Testing $$cpp_dir...$(NC)"; \
			cd "$$cpp_dir"; \
			for ex_dir in ex*/; do \
				echo "$(GREEN)Testing $$ex_dir...$(NC)"; \
				cd "$$ex_dir"; \
				make re > /dev/null 2>&1; \
				if [ -f prog ]; then \
					echo "$(GREEN)Running Valgrind for $${ex_dir}...$(NC)"; \
					./prog > /dev/null 2>&1; \
					echo "\n=== $$cpp_dir$$ex_dir ===" >> ../../../errors.log; \
					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./prog 2>> ../../../errors.log > /dev/null; \
					if [ $$? -ne 0 ]; then \
						echo "$(RED)Valgrind found errors in $${ex_dir}$(NC)"; \
						errors=1; \
					fi; \
				else \
					echo "$(RED)No executable found in $${ex_dir}$(NC)"; \
					errors=1; \
				fi; \
				cd ..; \
			done; \
			cd ..; \
		done; \
	fi; \
	if [ $$errors -eq 0 ]; then \
		echo "$(BOLD)$(GREEN)All tests passed successfully with no errors!$(NC)"; \
	else \
		echo "$(BOLD)$(RED)Tests completed with errors. Check errors.log for details.$(NC)"; \
	fi

%:
	@:

.PHONY: all clean test