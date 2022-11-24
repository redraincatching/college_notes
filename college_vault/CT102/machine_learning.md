# Intelligent Systems via Machine Learning

###### what is intelligence? what is an intelligent system?
-> can get more specific by considering the goals of intelligent systems
-> intelligent behaviour via computation

###### many areas of artificial intelligence is based on the concept of learning:
-> for a machine to be intelligent, it must be able to learn

###### why get machines to learn?
-> many real-world problems are complex, and it is difficult to specify how exactly to solve the problem or find a solution
-> learning techniques are used in many domains to find non-obvious answers

###### forms of animal and human learning
- environmental
- play
- repetition or rehearsal
- imitation
- formal vs. informal
- punishments vs rewards

###### how is rote learning implemented in information systems?
-> explicit programming of rules

###### how does machine learning work?
-> concerned with the design and development of programs which learn patterns present in input data (training data)

the learned patterns are then used to make predictions about unseen data
-> generalisability

---
## learning patterns
the patterns learned allow the program to generalise
in order to generalise, the program creates a mathematical model
the model contains information on what pattern has been found
different types of machine learning programs learn different types of models
the models they learn depend upon what kind of data they have been given

### training
machine learning techniques require a training stage to learn some general rule, or pattern (the mathematical model)

the training stage consists of a set of examples which can be:
- labeled (supervised) -> learning by example
- unlabelled (unsupervised) -> concept formulation

additional data may also be used to "tune" the model parameters (validation data) and test how good the model is (test data)

### machine learning approaches
#### symbolic:
knowledge is represented in the form of symbolic descriptions of the learned concepts, e.g. rules or hierarchies
examples:
- decision trees and rules for classification
- association rules (for market basket analysis)
- nearest-neighbour approach (for clusters)

#### sub-symbolic:
knowledge is represented in a non-human readable form, e.g. in structure, weights, and biases
examples:
- neural networks and deep learning

#### adaptive learning:
learning from interacting with the environment, e.g. reinforcement or evolutionary learning
examples:
- reinforcement learning
- genetic algorithms

### supervised learning
the training data consists of a set of training examples or instances
each example is a pair consisting of an {input, output} pair where the input object is typically a vector, and the output is the desired output value
the output value is often called the class
the parallel task in human learning is often called concept learning, where an abstract is inferred or derived from specific instances

the idea is:
learn patterns from the given data that will allow the machine learning technique to assign the correct output value to some unseen example

#### validation (supervised)
rather than just having one phase of learning (with the training data), and one phase of testing (with the test data), validation is often used, which used a portion of the test data (the validation data) to assess how well the model is being learned, and to potentially improve the model as a result.

#### 10-fold cross validation
the original dataset is split into 10 equally sized subsamples
one is used as a validation set, the other 9 are used to train it
repeated 10 times, using each sample as a validation set once, and then the results are averaged

#### testing
once the training and validation stage is complete the system must be tested with data not previously entered into the system
the test involves giving the system previously unseen data, and comparing the system answer with the real answer

### classification
the process of finding common properties among entities, and sorting them into classes based on that
often results in classification rules, which can be displayed by a decision tree
useful if the classes are known in advance

#### binary classification
two classes, 1 and 0, so generally only one output node is needed
e.g. spam or not spam

#### multiclass specification
extending binary classification into multiple output classes

![[binary_classification_tree.png]]
the numbers here mean out of the 50 samples in this run, the rule gave the right answer for <left_number> and then wrong answer for <right_number>

---
## unsupervised learning
the training data consists of a set of training examples (input objects typically represented as a vector), but there is no output class associated with each object
the idea is: to find similarities between the objects
- useful with recommender systems

### clustering
given a large input set, clustering partitions the set into clusters that maximise similarity
- used when the categories are unknown

### sub-symbolic approach - artificial neural networks
inspired by simplified (known) workings of the brain
neurons connected via links with each neuron possessing limited processing ability
no single "unit of computation", no cpu
can be used for classification and clustering

consists of a set of nodes, arranged as
- an input layer
takes instances of training data
- an output layer
outputs the result
- one or more hidden layers
![[simple_neural_network.png]]

an artificial nodes comprises:
- one or more input values, coming from other nodes
- one or more weights associated with each output
- one output value
- an activation function: some summation of the weights an values, giving an activation value
- a threshold value
![[sample_node_ann.png]]

a value will only be output from the node if the activation value is greater than the threshold value

#### how does learning take place?
for example, given a classification task and labelled training data
- in the output layer, the actual value $O_a$ is compared with the desired output value $O_d$, and the degree of error is calculated with $O_d - O_a$
                - the error is "back-propagated" by modifying weights according to the degree of error

#### recognising handwritten numbers
![[recognising_handwritten_images.png]]
 28x28 pixel image, so input is 784 binary values of white (1) or black (0)
the output consists of 10 nodes, only one of which will be on to indicate which number is recognised

### deep learning
new area using multiple layers of artificial neural networks
has made problems previously thought impossible, like audio or visual recognition, relatively easy today

#### characteristics
major difference to other approaches is with respect to how the training instances/objects are represented
deep learning attempts to find good representations itself by learning the representations using unlabelled data
specifically higher level representations are derived from lower level representations
-> basically, it does the preprocessing for you

---
## ethical concerns
- accuracy
- responsibility
- explainability
why certain actions were taken
- auditability
the ability to retrace and replicate actions
- bias

### robustness
what happens if an image is modified slightly?
![[robustness_1.png]]
![[robustness_2.png]]


> #algorithms