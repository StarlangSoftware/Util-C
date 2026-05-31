For Developers
============

You can also see [Java](https://github.com/starlangsoftware/Util), [Python](https://github.com/starlangsoftware/Util-Py), 
[Cython](https://github.com/starlangsoftware/Util-Cy), [Swift](https://github.com/starlangsoftware/Util-Swift), 
[Js](https://github.com/starlangsoftware/Util-Js), [CS](https://github.com/starlangsoftware/Util-CS), [Php](https://github.com/starlangsoftware/Util-Php), or [C++](https://github.com/starlangsoftware/Util-CPP) repository.

## Requirements

* [C Compiler](#c)
* [Git](#git)


### C
To check if you have compatible C Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called Util-C will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/Util-C.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu.

Detailed Description
============

+ [Interval](#interval)
+ [Subset](#subset)
+ [SubsetFromList](#subsetfromlist)
+ [Permutation](#permutation)

## Interval 

Aralık veri yapısını tutmak için Interval dosyası

	a = create_interval();

1 ve 4 aralığı eklemek için

	add_to_interval(a, 1, 4);

i. aralığın başını getirmek için (yukarıdaki örnekteki 1 gibi)

	int get_first_of_interval(Interval_ptr interval, int index)

i. aralığın sonunu getirmek için (yukarıdaki örnekteki 4 gibi)

	int get_last_of_interval(Interval_ptr interval, int index)

## Subset 

Altküme tanımlamak ve tüm altkümelere ulaşmak için Subset ve SubsetFromList sınıfları

Subset veri yapısını tanımlamak için

	Subset_ptr create_subset(int range_start, int range_end, int element_count)

Burada element_count elemanlı, elemanları range_start ile range_end arasında değerler alabilen
tüm altkümeleri gezen bir yapıdan bahsediyoruz. Örneğin

create_subset(1, 4, 2), bize iki elemanlı elemanlarını 1 ile 4 arasından gelen tüm alt kümeleri 
seçmek için kullanılan bir constructor'dır. Tüm altkümeleri elde etmek için

	a = create_subset(1, 4, 2);
	do{
		subset = a->set;
		....
	}while(a.next_subset());

Burada subset sırasıyla {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4} altkümelerini gezer. 

## SubsetFromList 

Altküme tanımlamak ve tüm altkümelere ulaşmak için Subset ve SubsetFromList sınıfları

SubsetFromList veri yapısını kullanmak için

	Subset_from_list_ptr create_subset_from_list(int* list, int list_size, int element_count);

Burada elementCount elemanlı, elemanları list listesinden çekilen değerler olan ve tüm 
altkümeleri gezen bir yapıdan bahsediyoruz. Örneğin

create_subset_from_list({1, 2, 3, 4}, 4, 3), bize üç elemanlı elemanlarını {1, 2, 3, 4} listesinden 
seçen ve tüm alt kümeleri gezmekte kullanılan bir constructor'dır. Tüm altkümeleri elde 
etmek için

	a = create_subset_from_list({1, 2, 3, 4}, 4, 3);
	do{
		subset = a->set;
		....
	}while(a.next_subset_from_list());

Burada SubsetFromList sırasıyla {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4} altkümelerini 
gezer. 

## Permutation

Permütasyon tanımlamak ve tüm permütasyonlara ulaşmak için Permutation sınıfı

	Permutation_ptr create_permutation(int n)

Burada 0 ile n - 1 arasındaki değerlerin tüm olası n'li permütasyonlarını gezen bir 
yapıdan bahsediyoruz. Örneğin

create_permutation(5), bize değerleri 0 ile 4 arasında olan tüm 5'li permütasyonları gezmekte 
kullanılan bir constructor'dır. Tüm permütasyonları elde etmek için

	a = create_permutation(5)
	do{
		permutation = a.n;
		...
	}while(a.next_permutation());

Burada Permutation sırasıyla {0, 1, 2, 3, 4}, {0, 1, 2, 4, 3} gibi permütasyonları gezer.

For Contibutors
============

### Conan Setup

1. First install conan.

pip install conan

Instructions are given in the following page:

https://docs.conan.io/2/installation.html

2. Add conan remote 'ozyegin' with IP: 104.247.163.162 with the following command:

conan remote add ozyegin http://104.247.163.162:8081/artifactory/api/conan/conan-local --insert

3. Use the comman conan list to check for installed packages. Probably there are no installed packages.

conan list

### conanfile.py file

1. Put the correct dependencies in the requires part
```
    requires = ["math_c/1.0.0", "data_structure_c/1.0.0", "classification_c/1.0.0"]
```

2. Default settings are:
```
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["ComputationalGraph"]
```

### CMakeLists.txt file
1. Set the C standard with compiler flags.
```
	set(CMAKE_C_STANDARD 17)
	set(CMAKE_C_FLAGS "-O3")
```
2. Dependent packages should be given with find_package.
```
	find_package(util_c REQUIRED)
	find_package(data_structure_c REQUIRED)
```
3. For library part, use add_library and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_library(Math src/Distribution.c src/Distribution.h src/DiscreteDistribution.c src/DiscreteDistribution.h src/Vector.c src/Vector.h src/Eigenvector.c src/Eigenvector.h src/Matrix.c src/Matrix.h src/Tensor.c src/Tensor.h)
	target_link_libraries(Math util_c::util_c data_structure_c::data_structure_c m)
```
4. For executable tests, use add_executable and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_executable(DiscreteDistributionTest src/Distribution.c src/Distribution.h src/DiscreteDistribution.c src/DiscreteDistribution.h src/Vector.c src/Vector.h src/Eigenvector.c src/Eigenvector.h src/Matrix.c src/Matrix.h src/Tensor.c src/Tensor.h Test/DiscreteDistributionTest.c)
	target_link_libraries(DiscreteDistributionTest util_c::util_c data_structure_c::data_structure_c m)
```

### Data files
1. Add data files to the cmake-build-debug folder.

### C files
1. Define structs as class counterparts.
```
	typedef struct {
	    double *data;       // Flattened data array
 	   	int *shape;         // Shape of the tensor
	    int *strides;       // Strides for each dimension
 	   	int dimensions;     // Number of dimensions
  	  	int total_elements;
	} Tensor;
```
2. Define also typedefs for pointer to those structs.
```
	typedef Tensor *Tensor_ptr;
```
3. Put all those definitions to the header files with prototypes of functions.
4. Constructor method(s) should allocate a pointer of struct and fill the details and return the pointer.
```
Vector_ptr create_vector(Array_list_ptr values) {
    Vector_ptr result = malloc_(sizeof(Vector));
    result->values = values;
    result->size = values->size;
    return result;
}
```
5. Destructor method should be defined for each struct and deallocate the object and its contents if allocated.
```
void free_vector(Vector_ptr vector) {
    free_array_list(vector->values, free_);
    free_(vector);
}
```
6. If there is multiple inheritance, then define the super class inside the subclass, which also should be defined inside its own subclass etc.
```
struct sgd_momentum {
    Optimizer optimizer;
    Hash_map_ptr velocity_map;
    double momentum;
};
struct Adam {
    Sgd_momentum sgd;
    Hash_map_ptr momentum_map;
    double beta2;
    double epsilon;
    double current_beta1;
    double current_beta2;
};
struct AdamW {
    Adam adam;
    double weight_decay;
};
```
7. If there is overloading, and subclasses should override the method, you can add pointers to the functions and set them in the constructor.
```
struct function {
    Function_type function_type;
    Tensor_ptr (*calculate)(const void*, const Tensor*);
    Tensor_ptr (*derivative)(const void*, const Tensor*, const Tensor*);
};
Elu_ptr create_elu(const double a) {
    Elu_ptr delu = malloc_(sizeof(Elu));
    delu->a = a;
    delu->function.function_type = ELU;
    delu->function.calculate = calculate_elu;
    delu->function.derivative = derivative_elu;
    return delu;
}
```
8. Instanceof could be done using an enumerated type defined in the parent class.
```
enum optimizer_type {
    OPTIMIZER, ADAM, ADAM_W, SGD_MOMENTUM, SGD,
};
typedef enum optimizer_type Optimizer_type;
struct optimizer {
    Optimizer_type type;
```
9. If needed, hash function should be declared for the struct.
```
	unsigned int hash_function_computational_node(const Computational_node *node, int N) {
    	return ((uintptr_t)node) % N;
	}
```
10. If needed, comparator function should be declared for the struct.
```
int compare_annotated_word(const Annotated_word *word1, const Annotated_word *word2) {
    return compare_string(word1->name, word2->name);
}
```
11. Data Structures: For hashmap, linked hash map and hashset, use create_hash_map, create_linked_hash_map, and create_hash_set in data structure library. There are default string and integer versions of hash_map.
```
Hash_map_ptr create_hash_map(unsigned int (*hash_function)(const void *, int), int (*key_compare)(const void *, const void *));
Linked_hash_map_ptr create_linked_hash_map(unsigned int (*hash_function)(const void *, int), int (*compare)(const void *, const void *));
Hash_map_ptr create_string_hash_map();
Hash_map_ptr create_integer_hash_map();
Hash_set_ptr create_hash_set(unsigned int (*hash_function)(const void *, int), int (*compare)(const void *, const void *));
```
12. Data Structures: For array list, use create_array_list in data structure library..
```
Array_list_ptr create_array_list();
```
13. Data Structures: For linked list, use linked_list in data structure library..
```
Linked_list_ptr create_linked_list(int (*compare)(const void *, const void *));
```
14. Data Structures: For queue and stack, use queue and stack in data structure library.
```
Queue_ptr create_queue();
Stack_ptr create_stack();
```
15. Data Structures: For hash map that is counting items, use counter hash map in data structure library.
```
Counter_hash_map_ptr
create_counter_hash_map(unsigned int (*hash_function)(const void *, int), int (*key_compare)(const void *, const void *));
```
16. Do not forget to comment each function.
```
	/**
 	* Initializes a tensor with given data and shape. Data is cloned in the tensor
	*
 	* @param data Flattened array representing the tensor data.
 	* @param shape Array representing the shape of the tensor.
 	* @param dimensions Size of the shape array.
 	* @return Pointer to the created tensor. Returns NULL on failure.
 	*/
	Tensor_ptr create_tensor(const double *data, const int *shape, int dimensions) {
```
17. Function names should follow snake case case.
```
	Tensor_ptr tensor_get(const Tensor *tensor, const int *dimensions, int size) {
```
18. All heap allocations should be done with malloc_, calloc_, realloc_ taken from the memory management library.
```
    int *new_shape = malloc_((tensor->dimensions - size) * sizeof(int));
```
19. All heap deallocations should be done with free_ taken from the memory management library.
```
    free_(new_shape);
```
20. DO NOT write getter and setter methods.
21. If there are multiple constructors for a class, define them as constructor1, constructor2, ....
```
Tensor_ptr create_tensor(const double *data, const int *shape, int dimensions);

Tensor_ptr create_tensor2(const int *shape, int dimensions);

Tensor_ptr create_tensor3(double *data, const int *shape, int dimensions);

Tensor_ptr create_tensor4(const int *shape, int dimensions);
```
22. Use separate main method for testing purposes.
```
int main() {
    start_medium_memory_check();
    testColumnWiseNormalize();
    testMultiplyWithConstant();
    testDivideByConstant();
    end_memory_check();
}
```
23. Testing main method should start with memory check and end with memory check.
```
int main() {
    start_medium_memory_check();
    testColumnWiseNormalize();
    testMultiplyWithConstant();
    testDivideByConstant();
    end_memory_check();
}
```
24. Enumerated types should be declared with enum.
```
enum category_type{
    MATHEMATICS, SPORT, MUSIC, SLANG, BOTANIC,
    PLURAL, MARINE, HISTORY, THEOLOGY, ZOOLOGY,
    METAPHOR, PSYCHOLOGY, ASTRONOMY, GEOGRAPHY, GRAMMAR,
    MILITARY, PHYSICS, PHILOSOPHY, MEDICAL, THEATER,
    ECONOMY, LAW, ANATOMY, GEOMETRY, BUSINESS,
    PEDAGOGY, TECHNOLOGY, LOGIC, LITERATURE, CINEMA,
    TELEVISION, ARCHITECTURE, TECHNICAL, SOCIOLOGY, BIOLOGY,
    CHEMISTRY, GEOLOGY, INFORMATICS, PHYSIOLOGY, METEOROLOGY,
    MINERALOGY
};
```
25. Every header file should start with
```
#ifndef MATH_DISTRIBUTION_H
#define MATH_DISTRIBUTION_H
```
and end with
```
#endif //MATH_DISTRIBUTION_H
```
26. Use regular package for regular expression handling.
```
	void check_match(char* expression, char* word){
    	Regular_expression_ptr re = create_regular_expression(expression);
    	if (!full_matches(re, word)){
        	printf("Mismatch %s %s\n", re->expression, word);
    	}
    	free_regular_expression(re);
	}
```
27. Do not forget to use const expression for parameters, if they will not be changed in the function.
```
bool frame_lexical_unit_exists(const Frame* frame, const char *synSetId);
```
28. For dynamic string handling, use util package with stringutils.
```
struct string {
    char *s;
    int max_size;
};
typedef struct string String;
typedef String *String_ptr;
String_ptr create_string();
String_ptr create_string2(const char *s);
String_ptr create_string3(const char* s1, const char* s2);
String_ptr create_string4(const char* s1, const char* s2, const char* s3);
```
29. Foor boolean type, use bool.
```
bool check_definition(const Data_set* data_set, const Instance* instance);
```
30. Use xmlparser package for parsing xml files.
```
    Xml_document_ptr doc = create_xml_document("test.xml");
