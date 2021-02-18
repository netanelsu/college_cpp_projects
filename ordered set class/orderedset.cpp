#include "orderedset.h"

int OrderSet::CheckArr(int *group, int size)
{
	int i,j,count=0;
	for (i = 0; i < (size-1); i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (group[i] == group[j])
				count++;
		}
	}
	return count;
}

bool OrderSet::CheckSort(int *group,int size)
{
	int i;
	for (i = 0; i < size - 1; i++) {
		if (group[i] > group[i + 1])
			return false;
	}
	return true;
}

void OrderSet::Sorter(int **group, int size)
{
	int i,temp;
	for (i = 0; i < size-1; i++) {
		if ((*group)[i] > (*group)[i + 1]){
		temp = (*group)[i];
		(*group)[i] = (*group)[i + 1];
		(*group)[i + 1] = temp;
	    }
	}
}

OrderSet::OrderSet()
{
	*group = NULL;
	size = 0;
}

OrderSet::OrderSet(int *arr, int Size)
{
	int i, l, j, count=0;
	count = CheckArr(arr, Size);
		if (count > 0) {
		size = Size - count;
		group = new int[size];
		group[0] = arr[0];
		l = 1;
		while (l < size) {
			for (i = 1; i < Size; i++) {
				count = 0;
				for (j = 0; j < i; j++) {
					if (group[j] == arr[i])
						count++;
				}
				if (count == 0) {
					group[l] = arr[i];
					l++;
				}
			}
		}
	}
	else {
		size = Size;
		group = new int[size];
		for (i = 0; i < size; i++) {
				group[i] = arr[i];
		}
	}
	while (!CheckSort(group,size)){
		Sorter(&group, size);
	}
}

OrderSet::OrderSet(const OrderSet & obj)
{
	int i,*grop;
	size = obj.size;
	group = new int[size];
	for (i = 0; i < size; i++) {
		group[i] = obj.group[i];
	}
//	cout << "copy constractor success" << endl;
}

OrderSet::~OrderSet()
{
	delete group;
//	cout << "destructor success" << endl;
}

int * OrderSet::getGroup()
{
	return group;
}

int OrderSet::getSize()
{
	return size;
}

void OrderSet::print()
{
	int i;
	cout << '{' << group[0];
		for (i = 1; i < size; i++) {
			cout << ',' << group[i];
	    }
		cout << '}' << endl;

}

bool OrderSet::ChangeGroup(int *arr, int Size)
{
	int i,count=0;
	for (i = 0; i < Size-1; i++) {
		if (arr[i] >= arr[i + 1])
			count++;
	}
	if (count != 0) {
		cout << "the arry is not legall gruop" << endl;
		return false;
	}
	else {
		delete group;
		size = Size;
		group = new int[size];
		for (i = 0; i < size; i++) {
			group[i] = arr[i];
		}
		return true;
	}
}

OrderSet OrderSet::DiffGroup(OrderSet p2)
{
	int i, j,l=0, count = 0,Size,*arr3;
	for (i = 0; i < size; i++) {
		for (j = 0; j < p2.size; j++) {
			if (group[i] == p2.group[j])
				count++;
		}
	}
	Size = size - count;
	arr3 = new int[Size];
	for (i = 0; i < size; i++) {
		count = 0;
		for (j = 0; j < p2.size; j++) {
			if (group[i]==p2.group[j])
				count++;
		}
		if (count == 0) {
			arr3[l] = group[i];
			l++;
		}
	}
	OrderSet p3(arr3, Size);
	return p3;
}

OrderSet OrderSet::InterSect(OrderSet p2)
{
	int i, j,l=0, count = 0,Size=0,*arr3;
	for (i = 0; i < size; i++) {
		for (j = 0; j < p2.size; j++) {
			if (group[i] == p2.group[j])
				Size++;
		}
	}
	arr3 = new int[Size];
	for (i = 0; i < size; i++) {
		count = 0;
		for (j = 0; j < p2.size; j++) {
			if (group[i] == p2.group[j])
				count++;
		}
		if (count > 0) {
			arr3[l] = group[i];
			l++;
		}
	}
	OrderSet p3(arr3, Size);
	return p3;
}

OrderSet OrderSet::UnionGroup(OrderSet p2)
{
	int *arr3, Size,i,j=0;
	Size = size + p2.size;
	arr3 = new int[Size];
	for (i = 0; i < size; i++) {
		arr3[j] = group[i];
		j++;
	}
	for (i = 0; i < p2.size; i++) {
		arr3[j] = p2.group[i];
		j++;
	}
	OrderSet p3(arr3, Size);
	return p3;
}

bool OrderSet::EqualGroup(OrderSet p2)
{
	int i;
	if (size != p2.size)
		return false;
	for (i = 0; i < size; i++) {
		if (group[i] != p2.group[i])
			return false;
	}
	return true;
}

bool OrderSet::EmptyGroup()
{
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool OrderSet::Contain(int num)
{
	int i,count=0;
	for (i = 0; i < size; i++) {
		if (num == group[i])
			count++;
	}
	if (count == 0) {
		return false;
	}
	else
		return true;
}

bool OrderSet::Contain(OrderSet p2)
{
	int i, j, count = 0;
	for (i = 0; i < p2.size; i++) {
		for (j = 0; j < size; j++) {
			if (p2.group[i] == group[j])
				count++;
		}
	}
	if (count == p2.size) {
		return true;
	}
	else {
		return false;
	}
}

