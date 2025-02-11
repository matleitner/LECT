# New decorator: @traced
# Decorator @traced modifies the function so that an execution trace is shown.
#
# PLEASE NOTE:
# This is not a required subject!
# You don't need to understand how this works.
# Just use the module as a service to trace the execution of functions.
#
# jmr@ua.pt 2016-10-14 (v2)
# 2017-12-03: Name changed from trace -> traced
# 2022-12-11: Changed to ASCII characters, for increased portability.

BAR    = "|   "     # "\u2502   " or  "│   "
ERROR  = "+~> "     
CORNER = "+-> "     # "\u2514\u2500\u2192 " or  "└─→ "

def traced(func):
    def tracedfunc(*args, **kwargs):
        sep = CORNER
        if traced.indent != None:
            indent = traced.indent  # save current indentation
            traced.indent += BAR
            print("{}{}{!r}{!r}".format(indent, func.__name__, args, kwargs))
        try:
            r = func(*args, **kwargs)   # CALL the func!
            return r
        except Exception as e:
            sep = ERROR
            r = e
            raise e
        finally:
            if traced.indent != None:
                print("{}{}{!r}".format(indent, sep, r))
                traced.indent = indent  # restore indentation
    
    return tracedfunc

# Initial tracing prefix:
traced.indent = ""

# Uncomment to turn off tracing by default:
#traced.indent = None

#traced.indent = traced.__dict__.get("indent")


if __name__ == "__main__":

    # How to use this module:
    from traced import traced
    
    # You can decorate a function definition
    @traced
    def func(x):
        return x + abs(2 - x)

    # You can redefine existing functions
    abs = traced(abs)

    # Then call the function to see the traced execution
    func(3)

