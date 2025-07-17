#include "Task_one.h"


void Task_one::read_file(){
    try
    {
        std::ifstream is("Task_One");
        if (!is)
        {
            throw FileError("File Couldnt be Read");
        }
        int dummy = 0;
        while (is >> dummy)
        {
            list_l.push_back(dummy);
            is >> dummy;
            list_r.push_back(dummy);
        }
    }
    catch (FileError& e)
    {
        std::cout << e.what() << std::endl;
    }
};

int Task_one::solve()
{
    read_file();
    std::ranges::sort(list_l);
    std::ranges::sort(list_r);
    int result = 0;
    for (int i = 0; i < list_l.size(); i++)
    {
        result += abs(list_l[i] - list_r[i]);
    }
    return result;
}

// GEHT AUCH SCHNELLER MIT 2 POINTER -> O(n log n ) + fürs Sortieren + O(n) fürs Durchgehen  anstatt O(n^2) !!
int Task_one::solve_2()
{
    read_file();

    int result = 0;
    int counter = 0;
    for (const int x : list_l)
    {
        for (const int y : list_r)
        {
            if (y == x)
            {
                counter++;
            }
        }
        result += (counter * x);
        counter = 0;
    }
    return result;
}

int Task_one::solve_2_quick() // 23387399 Lösung 21310593
{
    read_file();
    std::ranges::sort(list_l); // O(n log n)
    std::ranges::sort(list_r);// O(n log n)

    int l = 0;
    int r = 0;
    int sum = 0;
    int current_count = 1;
    while (l < list_l.size()) // O(n) -> 1 mal pro Element
    {
        if (list_l[l] == list_r[r])
        {
            // Wir zählen die Gesamteinträge des Aktuellen Werts.
            while (r < list_r.size()-1 && list_r[r] == list_r[r +1]) // insgesamt O(n) -> 1 mal pro Element
            {
                current_count++;
                r++;
            }
            sum += (current_count * list_l[l]);
            l++;
        }
        else
        {
            current_count = 1;
            //Zahlen sind nicht Gleich -> Zeiger auf Kleineres Objekt erhöhen
            if (list_l[l] < list_r[r])
            {
                l++;
            }
            else
            {
                r++;
            }
        }
    }
    return sum;
}