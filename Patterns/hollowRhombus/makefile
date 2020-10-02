NAME=drawDiamon
MOD=modules/
ALL=main.o verification.o Canvas.o engine.o
STD=c++2a

all: $(NAME)

$(NAME): $(ALL)
	g++ -o $@ -std=$(STD) $^

main.o: main.cpp
	g++ -c $^ -std=$(STD)

verification.o: $(MOD)verification.cpp
	g++ -c $^ -std=$(STD)

Canvas.o: $(MOD)Canvas.cpp
	g++ -c $^ -std=$(STD)

engine.o: $(MOD)engine.cpp
	g++ -c $^ -std=$(STD)

clean:
	rm -rf $(NAME) $(ALL)