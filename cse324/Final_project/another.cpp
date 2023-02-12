Value::p eval(Value::p x, Environment::p env) {
        if (x->type() == Value::SYMBOL) {                            // Look up the value
                Symbol::p x1 = dynamic_pointer_cast(x);
                return env->find(x1)[x1];
        } else if (x->type() != Value::LIST) {                       // Everything else scalar is self-evaluating
                return x;
        } else {
                List::p l = dynamic_pointer_cast<List>(x);                 // This is where it gets exciting
                list<Value::p> repr = l->to_list();
                if (repr.size() > 0 && repr.front()->type() == Value::SYMBOL) {
                        Symbol::p symbol = dynamic_pointer_cast<Symbol>(repr.front());
                        list<Value::p>::iterator it = ++(repr.begin());          // The second element, needed by most branches
                        list<Value::p>::iterator end = repr.end();               // The end of the list
                        if ((symbol->to_string()) == "quote") {                  // quote: Return the rest of the list
                                return List::create(++it, end);
