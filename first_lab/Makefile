CXX=g++
SRC_FILES = src/rect.cpp src/barrel.cpp src/my_string.cpp
TESTS = build/test_rect_basic_methods.out build/test_rect_operations.out build/test_rect_properties.out build/test_bounding_rect.out
OBJECTS = $(SRC_FILES:src/%.cpp=build/%.o)
CXXFLAGS = -std=c++17 -Wall -g

build:
	mkdir -p build
#3.1
#debug.out:
#CXX -g -0 debug.out main.cpp rect. cpp barrel. cpp matrix. cpp my_string. cpp

#3.2
#debug: build/debug.out
#		lldb build/debug.out
debug: build/debug.out
	lldb $<
# $< - первая зависимость: помогает избегать повторений в коде, убирает шанс ошибки в неверном написание имени/пути файла

#3.4
build/rect.o: src/rect.cpp src/rect.hpp

#build/barrel.o: src/barrel.cpp src/barrel.hpp
#		$(CXX) -g -c -o build/barrel.o src/barrel.cpp
#build/my_string.o: src/my_string.cpp src/my_string.hpp
#		$(CXX) -g -c -o build/my_string.o src/my_string.cpp

build/%.o: src/%.cpp src/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#было три отдельных правила для rect, barrel, my_string, стало одно универсальное правило для этих файлов

#build/debug.out: build/rect.o build/my_string.o build/barrel.o src/main.cpp
#		$(CXX) -g -o build/debug.out src/main.cpp build/rect.o build/my_string.o build/barrel.o

build/debug.out: $(OBJECTS) src/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
#переменная OBJECTS - позволяет не перечислять все объектные файлы 
#добавлены $@ - имя цели и $^ - все зависимости - не надо перечислять все make сам подставляет 

asan: CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: build/debug.out
	./build/debug.out
	
build/test_rect_basic_methods.out: tests/test_rect_basic_methods.cpp src/rect.cpp src/rect.hpp
	$(CXX) $(CXXFLAGS) -o $@ $< src/rect.cpp

#4.1
test_rect_basic_methods: build/test_rect_basic_methods.out
	./$<
	@echo "Тесты пройдены успешно"

#4.3
build/%.o: tests/test_%.cpp 
build/test_%.out: tests/test_%.cpp src/rect.cpp src/rect.hpp
	$(CXX) $(CXXFLAGS) -o $@ $< src/rect.cpp

test: $(TESTS)
	./build/test_rect_basic_methods.out
	./build/test_rect_operations.out
	./build/test_rect_properties.out
	./build/test_bounding_rect.out
	@echo "Все тесты пройдены успешно!"
clean:
	rm -rf build/*.o build/*.out

.PHONY: build debug asan test clean