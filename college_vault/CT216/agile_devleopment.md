# agile software development
- scrum project management methodology
- xp development methodology

## software development lifecycle
a software lifecycle is an abstract representation of a software process
defines the steps, methods, tools, deliverables, and activities of a process

_5 phases_
- requirements analysis
- system design
- implementation
- integration and deployment
- operation and maintenance

### the software process
a structured set of activities required to develop a software system
**four fundamental activities**
- specification
- development
- validation
- evolution

1) understand the problem
2) plan the solution
3) carry out the plan
4) test the end result

3 generic phases
- definition, _what?_
- development, _how?_
- maintenance, _change_

#### limitations
huge efforts in the design phase
not very flexible
staff are treated as a factor of production

## agile methods
focus on
- individuals and interaction
- working software over comprehensive documentation
- collaboration over contract negotiation
- responding to change over following a method

### scrum
agile management methodology
allows us to rapidly and repeatedly inspect actual working software
organisation sets the priorities, teams self-manage to determine the best way to deliver
every few weeks, real working software is produced, and it can be determined if it needs another iteration of work, or if it is ready for release

#### characteristics
- product progresses in a series of "sprints", 2-4 week periods of work towards a goal
- assumes that software cannot be well-defined, and requirements will change frequently
- requirements are captured as items in a list of "product backlogs"
- no specific engineering practices prescribed (xp, tdd, fdd)
        
##### product owner
- defines the features of the product
- tries to remove conjecture
- decides on release date/conduct
- be responsible for profitability (lmao)
- adjust features and priority every iteration
- accept or reject work results

##### scrum master
- represents management to the project
- responsible for enacting scrum values and practices
- removes impediments
- ensures that team is fully functional and productive
- enable close cooperation across all roles
- shield team form external interferences

##### scrum team
- typically 5-10 people
- cross-functional
- quality assurance, programmers, ui designers, etc.
- self-organising
- membership can only change between sprints



### sprints
- projects can only make progress in a series of sprints
- target duration one month, +/- a week or two
-> our aim will be two weeks, really
- product is designed, coded, and tested during those two weeks
- the output is a build which may or may not be a release
- then, move on to the next sprint

// note: no changes during a sprint
// plan sprint durations around how long you can commit to keeping change out of the project

#### sprint planning
![[sprint_planning.png]]
- team selects items from the project backlog that they can commit to completing
- sprint backlog is created
	- tasks are identified and time necessary for each is estimated (1-16 hrs)
	- team does this collaboratively
        
##### product backlog
list of all desired work on the project
usually a combination of
- story-based work ("let user find and replace")
- task-based work ("improve exception handling")

list is prioritised by project owner
priority groupings (high, medium, low...)

> #software_engineering 