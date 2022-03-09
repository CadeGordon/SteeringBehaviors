#pragma once
#include <exception>

template <typename T>
class DynamicArray
{


public:
	DynamicArray();
	~DynamicArray();
	void addItem(T item);
	void addItems(T item[], int size);
	bool removeItem(T item);
	void sortItems();
	int getLength();
	T getItem(int index);
	bool contains(T value);

	T operator [](int index);

private:

	T* m_items;
	int m_length;

};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_items;
	m_items = nullptr;
}


template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Create a new array with a size one greater than our old array
	T* tempArray = new T[getLength() + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		tempArray[i] = m_items[i];
	}
	//Set the last value in the new array to be the actor we want to add
	tempArray[getLength()] = item;
	//Set old array to hold the values of the new array
	delete[] m_items;

	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int size)
{
	for (int i = 0; i < size; i++)
		addItem(items[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check to see if the actor was null
	if (!item || getLength() <= 0)
	{
		return false;

	}

	bool itemRemoved = false;
	//Create a new array with a size one less than our old array
	T* tempArray = new T[getLength() - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i] || itemRemoved)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else if (!itemRemoved)
		{
			itemRemoved = true;
		}
	}
	//Set the old array to the new array
	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_length--;
	}
	//Return whether or not the removal was successful
	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T key;
	int j = 0;

	for (int i = 1; i < getLength(); i++)
	{
		key = m_items[i];
		j = i - 1;

		while (j >= 0 && m_items[j] > key)
		{
			m_items[j + 1] = m_items[j];
			j--;
		}

		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= m_length)
		return T();

	return m_items[index];
}

template<typename T>
inline bool DynamicArray<T>::contains(T value)
{
	//Iterate through actor array
	for (int i = 0; i < m_length; i++)
	{
		//return the current actor if it matches the argument
		if (m_items[i] == value)
			return true;
	}

	return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= m_length)
	{
		throw std::exception("index was outside the bounds of the array");
	}

	
	return m_items[index];
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

