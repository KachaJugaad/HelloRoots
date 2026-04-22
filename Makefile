CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
BUILD    = /tmp/helloroots

# Usage:
#   make run FILE=graphs/BFS        -> compile graphs/BFS.cpp and run it
#   make build FILE=graphs/BFS      -> compile only
#   make clean                      -> remove build artifacts

run: build
	@$(BUILD)/$(FILE)

build: $(BUILD)/$(FILE)

$(BUILD)/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BUILD)

.PHONY: run build clean
