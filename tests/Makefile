out=./out

all: cc

# e.g. make main
%: %.c
	mkdir -p ./$(out)
	$(CC) -static -O0 $^ -o $(out)/$@
	objdump -d --source-comment -Sr $(out)/$@ > $(out)/$@.s

# e.g. make run_main
run_%:
	taskset -c 0 $(out)/$(patsubst run_%,%,$@)

clean:
	rm -rf ./$(out)

.PHONY: all
