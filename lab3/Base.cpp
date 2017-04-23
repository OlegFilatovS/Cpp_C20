#include "Base.h"


MyData&  Base::operator[](const char *key) {

	//ищем сотрудника в базе 

	for (size_t i = 0; i < m_count; i++) {
		if (pBase[i]->m_key == key) 
			return pBase[i]->m_value;
	}

	//если сотрудник не найден,  добавляем (всегда!!!) 

	if(m_count == m_capacity) {
		
		m_capacity++;

		Pair **tmp = new Pair*[m_capacity];

		for (size_t i = 0; i < m_count; i++) {

			tmp[i] = pBase[i];

		}

		delete[] pBase;

		pBase = tmp;


	}

	//добавляем сотрудника

	pBase[m_count] = new Pair;

	pBase[m_count]->m_key = key;

	m_count++;
	
	return pBase[m_count - 1]->m_value;
}


Base& Base::operator=(Base&& bd) {

	pBase = bd.pBase;
	m_count = bd.m_count;
	m_capacity = bd.m_capacity;

	bd.pBase = nullptr;
	bd.m_count = 0;
	bd.m_capacity = 0;
	

	return *this;

}

Base::Base(Base&& bd) {

	*this = std::move(bd);


}


Base& Base::operator=(const Base& bd) {

	if (this != &bd) {


		if (m_capacity < bd.m_count) {

			Pair** tmp = new Pair*[bd.m_count];

			for (size_t i = 0; i < bd.m_count; i++) {

				tmp[i] = bd.pBase[i];

			}
			
			for (size_t i = 0; i < m_count; i++)
			{

				delete pBase[i];

			}

			delete pBase;

			pBase = tmp;

			m_count = bd.m_count;
			m_capacity = bd.m_capacity;

			delete tmp;

			return *this;


		}

		else
		{

			for (size_t i = 0; i < bd.m_count; i++)
			{
				delete pBase[i];

				pBase[i] = bd.pBase[i];

			}

			for (size_t i = bd.m_count; i < m_count; i++)
			{
				delete pBase[i];


			}

			m_count = bd.m_count;

			return *this;

		}


	}

	return *this;

}


Base::Base(const  Base& bd) {

	*this = bd;


}


int Base::deletePairForKey(const char*  key) {

	
	
	for (size_t i = 0; i < m_count; i++)
	{
		if (pBase[i]->m_key == key) { //нашли

			delete pBase[i]; //удалили
			m_count--;
			

			for (size_t j = i; j < m_count+1; j++) //смещаем позицию
			{
				pBase[j] = pBase[j + 1];

			}

			return i;
		}

	}
	
	return -1;
}


Base::~Base() {

	for (size_t i = 0; i < m_count; i++)
	{
		delete pBase[i];
	}

	delete[] pBase;
}


std::ostream& operator<<(std::ostream& os, const Base &bd) {

	os << "Database " << '\n';
	for (size_t i = 0; i < bd.m_count; i++) {
		os << *bd.pBase[i] << '\n';
	}
	return os;

}

void Base::printValueForKey(const char*  key) {

	try
	{
		for (size_t i = 0; i < m_count; i++)
		{
			if (pBase[i]->m_key == key) {

				std::cout << pBase[i]->m_key << std::endl;

				std::cout << pBase[i]->m_value << std::endl;

			}
		}

	}
	catch (const std::exception&)
	{

		std::cout << "There is no value for this key" << std::endl;

	}
	

}