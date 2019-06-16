#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class List
{
public:
	//缺省构造
	List():m_head(NULL),m_tail(NULL){};

	//拷贝构造
	List(List const& ls):m_head(NULL),m_tail(NULL)
	{
		for(Node* pnode = ls.m_head; pnode; pnode = pnode->m_next)
		{
			push_back(pnode->m_data);
		}
	}

	//析构函数
	~List()
	{
		clear();
	}

	//链表判空
	bool empty()
	{
		return m_head == NULL && m_tail == NULL;
	}

	//添加头节点
	void push_front(T const& data)
	{
		m_head = new Node(data,NULL,m_head);
		if(m_head->m_next)
			m_head->m_next->m_prev = m_head;
		else
			m_tail = m_head;
	}

	//删除头节点
	void pop_front()
	{
		Node* p_node = m_head->m_next;
		delete(m_head);
		m_head = p_node;
		if(p_node)
			p_node->m_prev = NULL;
		else
			m_tail = NULL;
	}

	//获取头节点数据
	T& front()
	{
		if(empty())
			throw underflow_error("front(): null node");
		return m_head->m_data;		
	}

	T const& front() const
	{
		return const_cast<List *>(this)->front();
	}
	
	//添加尾节点
	void push_back(T const& data)
	{
		m_tail = new Node(data,m_tail,NULL);
		if(m_tail->m_prev)
			m_tail->m_prev->m_next = m_tail;
		else
			m_head = m_tail;			
	}

	//删除尾节点
	void pop_back()
	{
		if(empty())
			return;
		Node* p_node = m_tail->m_prev;
		
		delete(m_tail);		

		m_tail = p_node;		
	
		if(p_node)
			p_node->m_next = NULL;
		else
			m_head = NULL;
	}

	//获取尾节点数据
	T& back()
	{
		if(empty())
			throw underflow_error("back(): null node");
		return m_tail->m_data;	
	}

	T const& back() const
	{
		return const_cast<List*>(this)->back();
	}

	//清空链表
	void clear()
	{
		if(!empty())
		{
			pop_front();
		}
	}

	//获取链表大小（节点个数）
	size_t size()
	{
		size_t size = 0;
		for(Node* node = m_head; node; node = node->m_next)
		{
			size += 1;
		}
		return size;
	}
	
	//重载输出流运算符
	friend ostream& operator<<(ostream& os, List<T>& ls)	
	{
		for(Node* pnode = ls.m_head; pnode; pnode = pnode->m_next)
		{
			os << pnode->m_data << ' '; 
		}
		return os;
	}

private:
	class Node
	{
	public:
		Node(T const& data, Node* prev = NULL, Node* next = NULL)
			: m_data(data),m_prev(prev),m_next(next){}
		Node* m_prev;
		Node* m_next;
		T m_data;
	};
	
public:
	//迭代类 也是一个嵌套类
	class iterator
	{
	public:
		iterator(Node* start = NULL, Node* end = NULL, Node* cur = NULL)
			: m_start(start), m_end(end), m_cur(cur){}

		T& operator*()
		{
			if(m_cur == NULL)
			{
				throw underflow_error("operator*() NULL");
			}
			return this->m_cur->m_data;
		}

		iterator& operator++()
		{
			if(m_cur == NULL)
			{
				m_cur = m_start;
			}
			else
				m_cur = m_cur->m_next;
			return *this;
		}
		
		iterator& operator--()
		{
			if(m_cur == NULL)
				m_cur = m_end;
			else
				m_cur = m_cur->m_prev;
			return *this;
		}

		bool operator==(iterator&  rh) const
		{
			return m_cur == rh.m_cur;
		}

		bool operator!=(iterator& rh) const
		{
			return !(*this == rh);
		}



	private:
		Node* m_start;
		Node* m_cur;
		Node* m_end;

	};

	//获取起始迭代器
	iterator begin()
	{
		return iterator(m_head, m_tail, m_head);
	}

	//获取终止迭代器（用于结束标志）
	iterator end()
	{
		return iterator(m_head,m_tail);
	}



	Node* m_head;
	Node* m_tail;

};

//模拟STL库
//----------------------------------------
//模拟傻瓜用户
void print(string const str, List<int>& ls)
{
	cout << str << endl;
	typedef List<int>::iterator IT;
	for(IT it = ls.begin(); it != ls.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl << "------------------" << endl;
}

int main()
{
	List<int> list_int;
	for(int i = 0; i < 5; i++)
	{
		list_int.push_front(i + 10);
	}

	for(int i = 0; i < 5; i++)
	{
		list_int.push_back(100 - i);
	}
	
	//cout << list_int << endl;
	print("添加节点后",list_int);

	list_int.pop_front();
	list_int.pop_back();
	
	//cout << list_int << endl;
	print("删除头尾节点后",list_int);


	return 0;
}
