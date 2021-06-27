SRCS			=	srcs/get_next_line.c\
					srcs/count.c
SRCH			=	srcsh/check_library_usage.c
CC				=	gcc
RM				=	rm -f
PIPE			=	&>./data/results.txt
EXE_C			=	count

all:			my code green

my:
				@$(RM) report.txt
				@$(CC) $(SRCS) srcs/main.c -o $(EXE_C)
				@read -p "Please enter file name with path: " file; \
				./$(EXE_C) $$file
code:
				@read -p "Please enter your main.c with path: " file; \
				$(CC) data/noheaders.c $$file -o $(EXE_C) $(PIPE) ||:

green:
				@$(CC) $(SRCH) srcs/get_next_line.c -o $(EXE_C)
				@./$(EXE_C)
				@echo Your report is ready
				@$(RM) $(EXE_C)
				@$(RM) data/noheaders.c
				@$(RM) data/results.txt
				@$(RM) data/headers

.PHONY:			all profile my code green