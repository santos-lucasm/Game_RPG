
## 1. Classes
	Standard programming class style
### 1.1 Public section
	Public section of classes will have methods to be utilized by many code sections and static
	const variables, mainly useful for debugging and tracing proposites.
### 1.2 Private section  
	Private section of classes will mainly consist of attributes to encapsulation, and some
	private methods that'll bring great reusability to the class
### 1.3 Protected section
	Protected class section will only exist for abstract or base classes, implementing methods
	to inheritance classes

### 1.4 Class comments
	Standard comment class style to be followed on class documentation

#### 1.4.1 Comments before classes definition
    /*
    @description
      This informs about the class, if it's used as an attribute of another class
      If it has a instance created on game initialization, or if it's a base or
      abstract class, or inherits another class.
    */
    class Game {};

#### 1.4.2 Comments on attributes
    public:
        /* static const values came here, no need to use _ before name */
        debugged = Traits<class>::debugged
    
    private:
        /* short one-line description */
        Clock _clock;

        /*
        @attribute
            In few cases, longer description 
        after @attribute keyword.
            private attributes must have _
        prior to its descriptional name.
        */
        AssetManager _manager;

#### 1.4.3 Comments on methods
    public:
        /*
        @method
            description (when to use, where is called)
        @parameters
            one line for each parameter (type espected
            and restrictions).
        @return
            return value when at normal condition,
            possible throw errors and invalid parameters also
        */
        void inputHandler( sf::Event event );
