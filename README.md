# Turn-based-Simulation-Game
Turn based Game sim written in C++ with ECS architecture

Some optimizations are missing: 

- Hard coded variables 
- define preprocessor instr that can be modified to constexpr or like this : ```static constexpr double PI = 3.14159;``` -> Compiler definitions and macros are replaced by the preprocessor before the compiler is ever run. This can make debugging very difficult because the debugger doesn't know where the source came from.
- possibly dangling pointers when the player is destroyed (weapon + armor) -> delete in destructor / std::make_unique / std::make_shared for more efficient memory blocks allocations and deallocations ? 
- Headers that can be replaced with forward declarations
- No check on components when == nullptr -> develop a homemade optional function (e.g std::functional in C++17)
- const on functions that don't modify internal state 
- use of std::move cheaper than copy ?
- naming conventions ("m_" prefix or "t_")
- manipulate stack and heap memory wisely and identify when copy / read only / move operations are needed
- Code repetition in Game class
- when fetching a component, study a way to use an alias and check for data availability like : ```using armor = getComponent...``` then nullptr can be checked easily (nullptr = false, so if pointer contains data, will be true)
- Rewrite class constructors with this style : ```Weapon(std::string&& name, int&& damage): m_name(name), m_damage(damage){}``` and default constructor (useful ? rule of 5 ?)
- Use of initializer lists like this : ```std::vector<ModelObject> mos{mo1, mo2};``` instead of : ```std::vector<ModelObject> mos; mos.push_back(mo1); mos.push_back(mo2);``` 
- no temp objects creations -> pass variables directly in functions like this : ```doSomething(getSomeModelObject(), getAnotherModelObject());```
- Prefer ```unique_ptr``` over ```shared_ptr``` -> no need to keep a track of copies, automatic destruction and better mem allocation
- ++i better than i++ : Pre-increment is faster than post-increment because it does not require a copy of the object to be made.
- Care about writing "\n" instead of '\n' : "\n" is interpreted as ```const char *``` and has to be parsed. '\n' on the other hand is known to be a single character and avoid a lot of CPU instructions.
- use of reference instead of a pointer if the nullptr value is not acceptable... reference can't be null and that way, bounds the execution and bad behaviors.
- perfect forwarding needed ? 
- throw error, resiliency ? catch ?

That was a focus on architecture and good practices (interfaces, modular, easy-to-extend) 


Work in progress (actively) to make it clean...
