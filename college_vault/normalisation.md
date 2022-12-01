# normalisation

normalisation
    chapter 14 in textbook
    normalisation rules give us a formal definition of why one grouping of attributes in a relation schema may be better than another

    normalised tables
        little to no redundancy
        no anomalies when deleting, inserting, or modifying data

    redundancy
        unnecessary duplication of data
        e.g.
            our company database
            what if employee had department data included?
                - each employee would have a department name, dno, mgrssn, and mgrstartdate
                    - dno is needed, as you need a link from employee to department
                    - however, the department name and manager don't change from employee to employee in the department
                    - therefore, while dno is duplicated, it is not redundant, but the other three are

    normalisation tests
        developed by codd, 1972
        takes each table through a series of tests to verify whther or not it belongs to a certain normal form (1F-5F)

    normalisation vs denormalisation
        normalised tables
            - redundancy reduced
            - storage space reduced
            - maintaining data integrity is easier
            - queries become more complex and take more time

        denormalised tables
            improve query times by introducing intentional redundancy


    functional dependency
        describes the relaitonship between attributes
        one of the main concepts of normalisation

        if A and B are attributes of a relation R, then B is functionally dependent (FD) on A if each value of B is associated with exactly one value of A

        values in B are uniquely determined by A

        notation
            A → B 
                FD from A to B
                B is FD on A
            /*
                A → B does not necessarily imply B → A
                A ↔ B denotes A → B and B → A
                A → {B, C} denotes A → B and A → C
                {A, B} → C denotes that it is the combination of A and B that uniquely determines C.
            */

        candidate key (CK)
            a key or combination thereof which could be used to determine all of the attributes of a relation
                i.e. a candidate for a primary key

        determining functional dependencies
            choose any PK or CK
            what attributes can be uniquely determined from another attribute

            e.g. in emp_proj(-ssn, pnumber-, hours, ename, pname, plocation)

                ssn → ename
                pnumber → {pname, plocation}
                {ssn, pnumber} → hours

                [[diagram]]

        /*
        NOTE:
            this cannot be inferred automatically, but must be inferred by someone who knows the _semantics_ of the relevant attributes
            you will, therefore, either be given a description of all FDs, or given enough informtion to infer them
        */

        full FDs
            a full FD {X, Y} → Z is a full functional depedency if when some attribute is removed from the left-hand side the dependency does not hold
        partial FDs
            partial FD is when if some attribute is removed from LHS, the dependency still remains
            
            // often asked which FDs are full from PK, and which are partial

        transitive FDs
            a functional dependency X → Y is transitive if in the relation R there exists a set of attributes Z such that neither is a CK nor a subset of any key of R and both
                
                X → Z 
                    and
                Z → Y

            [[diagram]]
            // note: dnumber is neither a key nor a subset of the key

        choosing CK from FD diagrams
            [[diagram]]
        
        inference rules for functional dependencies
            main obvious FDs are typically specified, call these F
            many others can be inferred, however, call these F^+, the closure of F

            for example
                F = {   A → {B, C, D, E}
                        E → {F, G}     }

                    some can then be inferred
                        A → A
                        A → {F, G}
                        E → F
                    etc.
            rules
                - reflexive
                    an attribute or set of attributes always determine themselves
                - augmentation
                    if X → Y, XZ →  YZ
                - transitive
                    if X → Y and Y → Z, then X → Z
                - decomposition
                    if X → YZ, then X →  Y
                - union
                    if if X → Y and X → Z, then X → YZ
                - pseudotransitive
                    if X → Y and WY → Z, WX → Z

normalisations - first normal form (1NF)
    a table is in 1NF if it has no repeating groups
        a group of attributes that occur a variable number of times in each record
        to ensure, choose appropriate primary key and split table if necessary
    
2NF
    a table is in 2NF if it is in 1NF and satisfies the following
        where there is a composite primary key, all non-key attributes must be fully functionally dependent on the whole primary key 

        example
            [[diagram]]

3NF
    in 3NF if in 2NF and there are no dependencies between attributes that are not primary keys

boyce-codd normal form (BCNF)
    a table in 3NF where there are no overlapping candidate keys