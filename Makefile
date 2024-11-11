CXXFLAGS = -Wall -Werror -Wextra -std=c++20
EXE=main.out
BUILD_PATH=./

.SILENT: clean clean_gcov_report clean_test_files

all: main.o
	g++ $(GCC_FLAGS) main.cpp -o $(BUILD_PATH)$(EXE) 

gen_gcov_report: main.o
	$(MAKE) -s clean_gcov_files
	g++ $(CXXFLAGS) --coverage main.cpp -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	echo "Report available at $(BUILD_PATH)report/index.html"
	
clean_gcov_files:
	rm -rf $(BUILD_PATH)*.gcda
	rm -rf $(BUILD_PATH)*.gcno

clean_lcov_files: 
	rm -rf $(BUILD_PATH)report
	rm -rf $(BUILD_PATH)coverage.info

clean_test_files:
	$(MAKE) -s clean_lcov_files --no-print-directory
	$(MAKE) -s clean_gcov_files --no-print-directory
	@echo "Test files has been cleaned."

clean:
	rm -rf $(BUILD_PATH)$(EXE)
	rm -rf $(BUILD_PATH)main.o