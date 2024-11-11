CXXFLAGS = -Wall -Werror -Wextra -std=c++20
EXE=main.out
BUILD_PATH=./

.SILENT: clean clean_test_files clean_gcov_files clean_lcov_files

all: main.o
	g++ $(GCC_FLAGS) main.cpp -o $(BUILD_PATH)$(EXE) 

gen_gcov_report: main.o
	$(MAKE) -s clean_gcov_files
	g++ $(CXXFLAGS) --coverage main.cpp -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c -d $(BUILD_PATH) --rc lcov_branch_coverage=1 --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info  --rc genhtml_branch_coverage=1 --output-directory $(BUILD_PATH)report/
	echo "Report available at $(BUILD_PATH)report/index.html"
	
clean_gcov_files:
	rm -rf $(BUILD_PATH)*.gcda
	rm -rf $(BUILD_PATH)*.gcno

clean_lcov_files: 
	rm -rf $(BUILD_PATH)report
	rm -rf $(BUILD_PATH)coverage.info

clean_test_files:
	$(MAKE) -s clean_lcov_files
	$(MAKE) -s clean_gcov_files
	echo "Test files has been cleaned."

clean:
	$(MAKE) -s clean_test_files
	rm -rf $(BUILD_PATH)$(EXE)
	rm -rf $(BUILD_PATH)main.o
	echo "Build files has been cleaned."