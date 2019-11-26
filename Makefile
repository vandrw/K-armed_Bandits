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
	$(RM) -r $(BUILDDIR)/* $(TARGET)/*

run:
	@echo "Running the file...\n";
	@$(TARGET)/$(OUTPUT)

debug:
	@echo "You are now in debugging mode.";
	@echo "All variables are set to their default values.\n";
	@$(TARGET)/$(OUTPUT) --debug