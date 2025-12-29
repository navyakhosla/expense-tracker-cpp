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
    cout << "* * * * Expense Tracker * * * * " << endl;
    cout << "option 1 - Add expense" << endl;
    cout << "option 2 - View expense" << endl;
    cin >> option;
    if (option == 1)
    {
        int account_id;
        float amount;
        string category;
        int n;
        cout << "enter account number";
        cin >> account_id;
        cout<<"how many expenses do you want to add";
        cin>>n;
        for(int i=0;i<n;i++){
        cout << "enter amount";
        cin >> amount;
        cout << "enter category- food,rent,education,medical,travel,shopping";
        cin >> category;
        t1.add_new_expense(account_id, amount, string_to_category(category));
    }}
    else if (option == 2)
    {
        int account_Id;
        cout << "enter account number";
        cin >> account_Id;
        t1.view_expense(account_Id);
    }
}