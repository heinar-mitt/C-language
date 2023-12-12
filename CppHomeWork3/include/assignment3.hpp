#pragma once
#include <functional>
#include <string>
#include <map>
namespace Homework
{   
    using Tasks = std::vector<std::pair<std::string, bool>>;
    Tasks assignment3();

    class Default
    {
    private:
        //Loo muutuja number, mis on tüüpi int ja väärtusega 0
        
    public:
        // Loo vaikiva konstruktori, ilma argumentideta
        
        // Loo konstruktor, mis võtab argumendiks int nimetusega i 
        // ja seab number väärtuseks i, deklareeri see siin
        
        // Loo default Copy konstruktor
        
        // Keela Move konstruktor kasutades delete
        
        // Loo default Copy omistamise operaator
        
        // Keela Move omistamise operaator kasutades delete
        
        // Loo default Võrdlus operaator
        
        // Loo default Spaceship <=> operaator
        
        // Loo default Destruktor 
        
    };

    
    class Op
    {
    private:
        // Loo muutuja number, mis on tüüpi float ja väärtusega 0.f
        
        
    public:
        // Vihje: Defineeri meetodid ja konstruktorid .cpp failis, 
        // siin ainult deklaratsioonid
        
        // Loo vaikiva konstruktori, ilma argumentideta
        
        // Loo konstruktor, mis võtab argumendiks float nimetusega i 
        // ja seab number väärtuseks i
        
        // Loo Copy konstruktor
        
        // Loo Move konstruktor
        
        // Loo Copy omistamise operaator
        
        // Loo Move omistamise operaator
        
        // Loo Võrdlus operaator
        
        // Loo Spaceship operaator
        
        // Loo Destruktor


    };
}