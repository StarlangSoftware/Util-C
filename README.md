For Developers
============

You can also see [Java](https://github.com/starlangsoftware/Util), [Python](https://github.com/starlangsoftware/Util-Py), 
[Cython](https://github.com/starlangsoftware/Util-Cy), [Swift](https://github.com/starlangsoftware/Util-Swift), 
[Js](https://github.com/starlangsoftware/Util-Js), [CS](https://github.com/starlangsoftware/Util-CS), or [C++](https://github.com/starlangsoftware/Util-CPP) repository.

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
