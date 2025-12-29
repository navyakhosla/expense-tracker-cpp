#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
enum class Category
{
    Food,
    Rent,
    Education,
    Medical,
    Travel,
    Shopping,
    Miscellaneous
};
class Expense
{
    float amount;
    Category category;

public:
    Expense(float amount, Category category)
    {
        this->amount = amount;
        this->category = category;
    }
    float getamount()
    {
        return amount;
    }
    Category getcategory()
    {
        return category;
    }
};
string category_to_string(Category s);
class Expense_Tracker
{
    unordered_map<int, vector<Expense>> expenses;

public:
    void add_new_expense(int id, float amount, Category category)
    {
        Expense e(amount, category);
        expenses[id].push_back(e);
    }
    void view_expense(int id)
    {
        for (auto &p : expenses)
        {
            if (p.first == id)
            { // p.first=key that is the accountId,p.second=value that is the vector<expense>
                for (Expense e : p.second)
                {
                    cout << "The amount is :" << e.getamount() << endl;
                    cout << "The category is :" << category_to_string(e.getcategory()) << endl;
                }
            }
        }
    }
    void filter_by_category(int id, Category cat)
    {
        if (expenses.find(id) == expenses.end())
        {
            cout << "no expense for this id" << endl;
        }
        bool find = false;
        for (Expense e : expenses[id])
        {
            if (e.getcategory() == cat)
            {
                cout << "amount : " << e.getamount() << endl;
                find = true;
            }
        }
        if (!find)
        {
            cout << "no expenses for this category";
        }
    }
    void filter_by_range(int id, float max, float min)
    {
        if (expenses.find(id) == expenses.end())
        {
            cout << "no expense for this category" << endl;
        }
        bool find = false;
        for (Expense e : expenses[id])
        {
            if (e.getamount() <= max && e.getamount() >= min)
            {
                cout << "Amount is" << e.getamount() << endl;
                find = true;
            }
        }
        if (!find)
        {
            cout << "no expenses in this range";
        }
    }
    void view_transactions(int id)
    {
        if (expenses.find(id) == expenses.end())
        {
            cout << "no transactions for this account" << endl;
        }
        unordered_map<string, vector<float>> transactions;
        for (Expense e : expenses[id])
        {
            string s = category_to_string(e.getcategory());
            transactions[s].push_back(e.getamount());
        }
        for (auto &p : transactions)
        {
            cout << "category is :" << p.first << endl;
            for (int amount : p.second)
            {
                cout << "amount : " << amount << endl;
            }
        }
    }
};
Category string_to_category(string s)
{
    if (s == "food")
        return Category ::Food;
    if (s == "rent")
        return Category ::Rent;
    if (s == "education")
        return Category ::Education;
    if (s == "medical")
        return Category ::Medical;
    if (s == "shopping")
        return Category ::Shopping;
    if (s == "travel")
        return Category ::Travel;
    return Category::Miscellaneous;
}
string category_to_string(Category s)
{
    if (s == Category::Food)
        return "food";
    if (s == Category::Rent)
        return "rent";
    if (s == Category::Education)
        return "education";
    if (s == Category::Travel)
        return "travel";
    if (s == Category::Shopping)
        return "shopping";
    if (s == Category::Medical)
        return "medical";
    return "miscellaneous";
}
int main()
{
    Expense_Tracker t1;
    int option;
    while (true)
    {
        cout << "* * * * Expense Tracker * * * * " << endl;
        cout << "option 1 - Add expense" << endl;
        cout << "option 2 - View expense" << endl;
        cout << "option 3 - Filter Expenses" << endl;
        cout << "option 4 - View Transactions" << endl;
        cout << "option 5 - Exit" << endl;
        cin >> option;
        if (option == 1)
        {
            int account_id;
            float amount;
            string category;
            int n;
            cout << "how many expenses do you want to add : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "enter account number : ";
                cin >> account_id;
                cout << "enter amount : ";
                cin >> amount;
                cout << "enter category- food,rent,education,medical,travel,shopping : ";
                cin >> category;
                t1.add_new_expense(account_id, amount, string_to_category(category));
            }
        }
        else if (option == 2)
        {
            int account_Id;
            cout << "enter account number : ";
            cin >> account_Id;
            t1.view_expense(account_Id);
        }
        else if (option == 3)
        {
            int account_id;
            cout << "enter account id : ";
            cin >> account_id;
            int f_option = 0;
            cout << "option 1 - Filter by category" << endl;
            cout << "option 2 - Filter by range" << endl;
            cin >> f_option;
            if (f_option == 1)
            {
                string cate;
                cout << "enter category(food,rent,education,shopping,medical,travel) : " << endl;
                cin >> cate;
                t1.filter_by_category(account_id, string_to_category(cate));
            }
            else if (f_option == 2)
            {
                float min_range, max_range;
                cout << "enter minimum range : ";
                cin >> min_range;
                cout << "enter maximum range : ";
                cin >> max_range;
                t1.filter_by_range(account_id, min_range, max_range);
            }
        }
        else if (option == 4)
        {
            int account_id;
            cout << "enter account_id : " << endl;
            cin >> account_id;
            // t1.view_transactions(account_id);
        }
        else if (option == 5)
        {
            cout << "* Exiting......... bye bye....*" << endl;
            break;
        }
    }
}