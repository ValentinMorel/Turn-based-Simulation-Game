# Turn-based-Simulation-Game
Turn based Game sim written in C++ with ECS architecture

Some optimizations are missing: 

- Hard coded variables
- Headers that can be replaced with forward declarations
- No check on components when == nullptr
- const on functions that don't modify internal state + references
- use of move constructor for Unit class -> cheaper than copy, no residual variables in memory (use of && for rvalues in func signature and std::move in call) 
- naming conventions ("m_" prefix or "t_")
- manipulate stack and heap memory more wisely and identify when copy / read only / move operations are needed
- Code repetition in Game class

That was a focus on architecture and good practices (interfaces, modular, easy-to-extend) 
