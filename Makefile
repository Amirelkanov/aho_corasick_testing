CXXFLAGS = -Wall -Werror -Wextra -g -o0 -fno-inline -std=c++11 -fno-exceptions
EXE=main.out
BUILD_PATH=./

all: main.o
	g++ $(GCC_FLAGS) main.cpp -o $(BUILD_PATH)$(EXE) 

gen_gcov_report: main.o
	$(MAKE) -s clean_gcov_files
	g++ $(CXXFLAGS) --coverage main.cpp -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c --no-external -d $(BUILD_PATH) --rc lcov_branch_coverage=1 --output-file $(BUILD_PATH)coverage.info
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

.SILENT: clean clean_test_files clean_gcov_files clean_lcov_files

.PHONY: clean clean_test_files clean_gcov_files clean_lcov_files