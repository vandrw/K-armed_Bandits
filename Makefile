CC := g++ # This is the main compiler
SRCDIR := src
BUILDDIR := build
TARGET := bin
OUTPUT := bandit
	
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	$(CC) $^ -o $(TARGET)/$(OUTPUT)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@$(RM) -r $(BUILDDIR)/* $(TARGET)/* data/*;

run:
	@clear
	@echo "Running the file...\n";
	@$(TARGET)/$(OUTPUT) $(ARGS)

graph:
	@python docs/graph.py

all:
	@$(MAKE) -s clean;
	@$(MAKE) -s;
	@$(MAKE) -s run ARGS="1 1";
	@$(MAKE) -s run ARGS="1 2";
	@$(MAKE) -s run ARGS="1 3";
	@$(MAKE) -s run ARGS="1 4";
	@$(MAKE) -s run ARGS="2 1";
	@$(MAKE) -s run ARGS="2 2";
	@$(MAKE) -s run ARGS="2 3";
	@$(MAKE) -s run ARGS="2 4";
	@$(MAKE) -s graph;