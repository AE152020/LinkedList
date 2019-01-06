//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#ifndef PRECOND_VIOLATED_EXCEPT__
#define PRECOND_VIOLATED_EXCEPT__

class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "")
		: std::logic_error(std::string("Precondition Violated Exception: ") + message){} 

}; 

#endif