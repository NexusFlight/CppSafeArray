#pragma once
//create this as a template that allows the use of different classes as its Type
template <class T>
class SafeArray
{
	//create a double pointer named _array
	T** _array;
	int _length;
	int _position = 0;

	//private method resizeArray, This creates a new array transfers the elements from the previous and overwrites the original
	void resizeArray()
	{
		//create new double pointer with the length of the previous plus 1
		T** newArray = new T*[_length + 1];
		//itterate equal to the length of the old pointer
		for (int i = 0; i < _length; i++)
		{
			//assign the data from the old array variable to the newArray
			newArray[i] = _array[i];
		}
		//assign the newArray to _array overwriting the original data
		_array = newArray;
		//increament length
		_length++;
		//assign the newArray variable null to write over the information stored in memory to prevent memory leaks
		newArray = NULL;
	}

public:
	//SafeArray Constructor
	SafeArray(int length) {
		//assign array a new pointer with the passed length argument
		_array = new T*[length];
		//assign length to the passed argument
		_length = length;
	}

	//SafeArray Destructor
	~SafeArray() {
		//assign the array null to wipe the information
		_array = NULL;
	}

	//getLength function
	int getLength()
	{
		return _length;
	}

	//getItem function returns a pointer to the item
	T* getItem(int index)
	{
		return _array[index];
	}

	//setItem procedure
	void setItem(T* item, int index)
	{
		//assign to array the item passed in to the index location
		_array[index] = item;
	}

	//addItem procedure
	void addItem(T* item)
	{
		//determine if the array is at max size
		if (_position >= _length)
		{
			//call resizeArray
			resizeArray();
		}
		//assign item to the last position of array
		_array[_position] = item;
		//increment position by 1
		_position++;
	}


};

