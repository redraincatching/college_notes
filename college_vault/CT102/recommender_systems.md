# Recommender systems
a system that suggests items to a user to support decision-making processes
these systems tend to use preferences and ratings, as well as social links

preferences and ratings are indicative of a user's likes or dislikes
-> this data can be gathered implicitly or explicitly
- explicitly - rate/like something
- implicitly - watching/listening to something

### Implicit Ratings
numeric representations are usually stored, and these may be gathered and weighted over time
usually in one of these ranges
- 0, 1 (binary)
- -1, 0, 1 (like, dislike, nothing)
- 1-5, 1-10 (star system)


_// note: larger scales aren't always better, people "prefer" different portions of the scale_

numeric rating and preference data can be interpreted as a matrix
_// most entries would be zero (sparsity, often >99%)_

---
###### Preferences vs. Ratings & Reviews
reviews have content, and may be more nuanced or difficult to process

ratings =~= preferences
implicit preferences are generally more "noisy" than explicit ones, and are more plentiful

---
#### Profiles
user profiles - all the preference data stored for a user				
&nbsp&nbsp&nbsp&nbsp// note: also holds preference history for a user

item profiles - the preference data for a user

can be stored in a [[databases|database]] or freeform (structured or unstructured)

##### using this data

can be used for _personalised_ or _non-personalised_ recommendations  
can be handled in several ways
- databases
- statistical (correlation) approach
- matrix factorisation
- machine learning

###### non-personalised recommendations
list of items generated for everyone
useful for new users, or to offer diversity to users
based on several attributes
- popularity: how many people watch it
- newness: how recently it became available
- velocity: rate of popularity growth

**implementation**
keep an ordered list of content ids, based on the above weighted attributes

---
## user preferences
### content-based recommendation
recommends items based on the similarity to previous items this user has interacted with
-> essentially, matching user profile attributes with content object attributes

the attributes used are domain-specific, and ideally well defined (i.e. structured using tags) so meaningful queries can be performed on them
-> in the absence of this structure, the main descriptive terms can be matched more generally
-> in either case, more recent attributes are weighted higher

**advantages & disadvantages**
- no cold start problem (similarity to other items, no user info necessary)
- no popularity bias
- attributes can be weighted differently for specificity (sci-fi < dystopia)
- can provide an explanation (because you watched this...)
- item content must be machine readable
- "stereotyping" possible; only similar to your previous preferences
- serendipity difficult

> content based approaches are good at exploitation (good at using the data they have) but not at exploration (finding new data)

### collaborative-based recommendation
the preferences of other users with whom user a shares preferences with
doesn't use content data
tries to mimic "word of mouth"

**advantages over content filtering**
- support for recommendations where content attributes are abstract
- easier to support issues of taste
- serendipitous recommendations possible

---
### Matrix data representation
*matrix sparsity* - in real data, the vast majority (~99%) of values in these datasets are 0
this can make it difficult to find similarity between users

##### Collaborative filtering approach
modern approaches use machine learning
a common technique is a statistical user-user or item-item comparison
-> neighbour-based approaches which find groups of similar users or items
// it is more practical to store item groups

---
## Pearson correlation
weighted average of deviations from neighbours' mean
steps:
1) calculate user-user or item-item similarity
2) select neighbourhood
3) give recommendations

1. finds average of ratings a user gives, as "like" is different for different people -> generally just calculated once and stored
   result will be in the range \[-1, 1\]
   _// this is a vector similarity comparison, similar to that found in a [[similarity_and_page_rank#Vector Space Model Approach|search engine]]_
![[pearson_correlations.png]]

2. some approaches:
	- correlation threshold
    users with similarity above a certain threshold are selected
    this threshold is usually slightly over 0

	- best-n correlations
    where the n neighbours who have the highest similarity are chosen

3. for some active user
   make recommendations on items neighbours have rated but this user has not
   // often the weighted average of these ratings is used
![[pearson_generate_recommendation.png]]

### hybrid recommender approaches
combine multiple approaches
depend on available data
usually combine popularity, content, and collaborative approaches

> #algorithms 