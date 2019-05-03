SRCDIR = .
BUILD_DIR = $(SRCDIR)/build
INSTALL_DIR = $(BUILD_DIR)/install
OBJ_DIR = $(BUILD_DIR)/obj
DOC_DIR = $(BUILD_DIR)/doc
SRCFILES = $(wildcard $(SRCDIR)/*.cc)
OBJFILES = $(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.cc,%.o,$(SRCFILES))))

LIB = $(BUILD_DIR)/libimageio.a
TEST = $(BUILD_DIR)/image-test

CXX = g++

INCLUDEDIRS = -I.. -I$(SRCDIR) -I$(SRCDIR)/..

CXXFLAGS = -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls -Wstrict-null-sentinel -Wsign-promo -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c $(INCLUDEDIRS)
LFLAGS = -Wall

ifeq ($(UNAME), Darwin)
    CXXFLAGS += -Wno-unknown-warning-option
endif

make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $1

all: $(LIB) $(TEST)

$(LIB): $(BUILD_DIR) $(OBJFILES)
	@echo "==== Linking $@. ===="
	ar rcs $(LIB) $(OBJFILES) $@

$(BUILD_DIR) $(OBJ_DIR) $(INSTALL_DIR) $(DOC_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRCDIR)/%.cc $(OBJ_DIR)
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c  -fPIC -o  $@ $<

$(OBJ_DIR)/main.o: $(LIB) $(OBJ_DIR) test/main.cc
	$(CXX) $(CXXFLAGS) -c test/main.cc -o $(OBJ_DIR)/main.o

$(TEST): $(OBJ_DIR)/main.o
	echo $@ $<
	$(CXX) $(LFLAGS) -L$(BUILD_DIR) $< -o $@ -limageio

install: $(LIB) $(INSTALL_DIR) documentation
	mkdir -p $(INSTALL_DIR)/include/imageio
	mkdir -p $(INSTALL_DIR)/lib
	mkdir -p $(INSTALL_DIR)/doc
	cp *.h $(INSTALL_DIR)/include/imageio
	cp $(BUILD_DIR)/libimageio.a $(INSTALL_DIR)/lib
	cp -r $(DOC_DIR)/html $(INSTALL_DIR)/doc/imageio

documentation: $(DOC_DIR)
	doxygen doc/Doxyfile

clean:
	rm -rf $(BUILD_DIR)
