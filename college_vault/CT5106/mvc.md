# mvc architecture
## model
represents the application data
includes the logic to manage access to and modification of data
usually represented by java classes or beans

## view
the view presented to the user, and handles user interactions
gets data from the model the model and specifies how that's presented
forwards user data to controller
html and jsps

## controller 
the glue between the model and the view, responsible for controlling the flow of the program as well as processing updates from the model to the view, and vice versa
a controller selects the next view to display based on user interaction and the outcome of the model operations
implemented as servlets or jsfs

> #software_engineering #java 