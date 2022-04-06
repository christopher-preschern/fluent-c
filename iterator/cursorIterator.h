typedef struct ITERATOR* ITERATOR_HANDLE;

ITERATOR_HANDLE createIterator();

char* getNextLoginName(ITERATOR_HANDLE iterator);

void destroyIterator(ITERATOR_HANDLE iterator);


