//AHTISHAM AHMED 014-BSCS/Fa21
#include <iostream>
using namespace std;

class employee {
public:
	string name;
	int id;
	int salary;
	employee* next;
};

employee* head = NULL;

class list : public employee {
public:
	int count = 0;
	employee* create_node() {
		employee* newnode = new employee;
		return newnode;
	}

	void read_node(employee* newnode) {
		cout << "ENTER THE EMPLOYEE NAME : "; cin >> newnode->name; cout << endl;
		cout << "ENTER THE EMPLOYEE ID : "; cin >> newnode->id; cout << endl;
		cout << "ENTER THE EMPLOYEE SALARY : "; cin >> newnode->salary; cout << endl;
	}

	void insert_at_head(employee* newnode) {
		if (head == NULL) {
			head = newnode;
			head->next = NULL;
			count++;
		}
		else {
			newnode->next = head;
			head = newnode;
			count++;
		}
	}

	employee* find_last() {
		employee* temp = head;
		employee* last_node = NULL;
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			last_node = temp;
			return last_node;
		}
	}

	employee* find_sec_last() {
		employee* temp = head;
		employee* sec_last_node = NULL;
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			sec_last_node = temp;
			return sec_last_node;
		}
	}

	void insert_at_end(employee* newnode) {
		if (head == NULL) {
			head = newnode;
			head->next = NULL;
			count++;
		}
		else {
			employee* last_node = find_last();
			last_node->next = newnode;
			newnode->next = NULL;
			count++;
		}
	}

	employee* find_target() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* temp = head->next; employee* prev = head;
			int ins_custom; int count_ = 0;
			cout << "ENTER THE NODE NUMBER AT WHICH YOU WANT TO INSERT"; cin >> ins_custom; cout << endl;
			if (ins_custom <= count) {
				while (prev != NULL) {
					count_++;
					if (count_ == ins_custom) {
						return prev;
						prev = prev->next;
						temp = temp->next;
					}
					else {
						prev = prev->next;
						temp = temp->next;
					}
				}
			}
		}
	}

	void insert_at_target() {
		employee* prev = find_target();
		employee* temp = prev->next;
		employee* newnode = create_node();
		read_node(newnode);
		employee* prev_next = temp;
		prev->next = newnode;
		newnode->next = prev_next;
	}

	employee* find_prev_target() {
		int emp_id;
		cout << "ENTER THE EMPLOYEE ID WHO YOU WANT TO DELETE"; cin >> emp_id;
		if (head->id == emp_id) {
			employee* temp = head;
			head = head->next;
			delete(temp);
		}
		else {
			employee* temp = head->next; employee* prev = head;
			while (temp != NULL) {
				if (temp->id == emp_id) {
					return prev;
				}
				else {
					prev = prev->next;
					temp = temp->next;
				}
			}
		}
	}

	void delete_at_head() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else if (head->next == NULL) {
			employee* temp = head;
			head = NULL;
			delete(temp);
		}
		else {
			employee* temp = head;
			head = head->next;
			delete(temp);
		}
	}

	void delete_at_end() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* sec_last = find_sec_last();
			employee* last = find_last();
			sec_last->next = NULL;
			delete(last);
		}
	}

	void delete_at_target() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* prev_cur = find_prev_target();
			employee* to_be_deleted = prev_cur->next;
			employee* to_be_deleted_next = prev_cur->next->next;
			prev_cur->next = to_be_deleted_next;
			delete(to_be_deleted);
		}
	}

	void find_highest_paid() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* temp = head;
			int max_sal = 0;
			employee* max = NULL;
			while (temp != NULL) {
				if (temp->salary > max_sal) {
					max_sal = temp->salary;
					max = temp;
				}
				else {
					temp = temp->next;
				}
			}
			cout << "THE HIGHEST PAID EMPLOYEE IS" << endl;
			cout << "** **" << endl;
			cout << "NAME : " << max->name << endl;
			cout << "ID : " << max->id << endl;
			cout << "SALARY : " << max->salary << endl;
			cout << "** **" << endl;
		}
	}

	void display_all() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* temp = head;
			while (temp != NULL) {
				cout << "** **" << endl;
				cout << "NAME : " << temp->name << endl;
				cout << "ID : " << temp->id << endl;
				cout << "SALARY : " << temp->salary << endl;
				cout << "** **" << endl;
				temp = temp->next;
			}
		}
	}

	employee* search_by_id() {
		int id_search;
		cout << "ENTER THE EMPLOYEE'S ID THAT YOU WANT TO DISPLAY"; cin >> id_search; cout << endl;
		employee* temp = head;
		while (temp != NULL) {
			if (id_search == temp->id) {
				return temp;
			}
			else {
				temp = temp->next;
			}
		}
	}

	void display_specific() {
		if (head == NULL) {
			cout << "THE LIST IS EMPTY" << endl;
		}
		else {
			employee* temp = search_by_id();
			cout << "** **" << endl;
			cout << "NAME : " << temp->name << endl;
			cout << "ID : " << temp->id << endl;
			cout << "SALARY : " << temp->salary << endl;
			cout << "** **" << endl;
		}
	}
};

int main() {
	list l;
	int opt = 0;
	while (1) {
		cout << "ENTER 1 TO INSERT A NODE AT HEAD" << endl;
		cout << "ENTER 2 TO INSERT A NODE AT END" << endl;
		cout << "ENTER 3 TO INSERT A NODE AT TARGET" << endl;
		cout << "ENTER 4 TO DELETE A NODE AT HEAD" << endl;
		cout << "ENTER 5 TO DELETE A NODE AT END" << endl;
		cout << "ENTER 6 TO DELETE A NODE AT TARGET" << endl;
		cout << "ENTER 7 TO FIND HIGHEST PAID EMPLOYEE" << endl;
		cout << "ENTER 8 TO DISPLAY ALL NODES" << endl;
		cout << "ENTER 9 TO DISPLAY A SPECIFIC NODE" << endl;
		cin >> opt; cout << endl;
		switch (opt) {
		case 1:
		{
			employee* newnode = l.create_node();
			l.read_node(newnode);
			l.insert_at_head(newnode);
			break;
		}

		case 2:
		{
			employee* newnode = l.create_node();
			l.read_node(newnode);
			l.insert_at_end(newnode);
			break;
		}

		case 3:
		{
			l.insert_at_target();
			break;
		}

		case 4:
		{
			l.delete_at_head();
			break;
		}

		case 5:
		{
			l.delete_at_end();
			break;
		}

		case 6:
		{
			l.delete_at_target();
			break;
		}

		case 7:
		{
			l.find_highest_paid();
			break;
		}

		case 8:
		{
			l.display_all();
			break;
		}

		case 9:
		{
			l.display_specific();
			break;
		}
		}
	}
}
/*
create_node() //
read_node() //
insert_at_head() //
insert_at_end() //
find_target() //
insert_at_target() //
delete_at_head() //
delete_at_end() //
find_prev_target()
delete_at_target()
find_sec_last() //
find_last() //
display_all() //
display_specific() //
find_highest_paid() //
*/