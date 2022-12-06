# file organisation

we can generally assume that, for non-trivial databases, the whole database will not fit in ram
one of the dbms' tasks is managing the physical organisation (storage and retrieval) of the tuples in each table of the database

// note: newer database system architectures, such as sap hanna, manage their databases in virtual memory, and allow the os to manage the movement of physical data through os paging

// TODO: link to os paging in [[ct213]]

## definition: file organisation
the way tuples are physically arranged in secondary storage to facilitate queries
    
### number of relevant factors
- fast data access
- cost
- efficient use of secondary storage space
- provisions for table growth

### options for storing the tuples
sequentially?
spaced according to some logical grouping?
### issues
compact storage
convenient and quick access

>/* 
>some semantics for file systems
> - tuple = record
> - attribute = field
>*/

---
## records
each record often begins with a header, a fixed-length region that stores information about the record, such as
- pointer to the database schema
- length of the record
- timestamp indicating the last interactions
- pointers to fields

### blocks
// roughly, block = frame = page
where records from a file are assigned to blocks
therefore, a table can be defined as a collection of blocks, containing records

the lock is a unit of data transfer between secondary storage and memory
the block size, B, is fixed
typically, B > |r|, so a block will contain multiple records
-> however, some records may not fit, and will _span_ over multiple blocks

blocks also have header information
- links to one or more associated blocks
- which table the block belongs to
- timestamp of last access

![[blocks_0.png]]
![[blocks_1.png]]

#### blocking factor
the average number of records that fit in a block
given block size B, in bytes, and record size r, in bytesm then with B >= R, a block can contain floor(B/R) records
// accounting for the size of headers, of course

##### spanned vs. unspanned organisation
- spanned: records can span more than one block
- unspanned: records cannot span, therefore can only use when B >= r

###### why use blocking?
when retrieving 1000 records, with a blocking factor of 10, we can reduce the number of data transfers (which are far slower than cpu operations) from 1000 to 100

--- 
## operations usuable on files
similar to those on databases
- scan or fetch records
- search for records that satisfy an equality condition
- search for a bounded value
- insert/delete

### searching
- locate relevant blocks
- move these to main memory buffers
- search through for required record
- worst case: retrieve and search all blocks for desired record

### to support record operations, must keep track of
- blocks associated with a file
- free space on blocks
- records on a block

## options for organising records
- heap file organisation (unordered)
- sequential file organisation (ordered)
- hashed file organisation
- indexed file organisation

### heap organisation
#### approach
any record is placed in any block where there is space
#### insertion
last disk block associated with file copied into buffer, and record is added; block then copied to disk
#### searching
must search all blocks (linear)
#### deletion
search, then delete link to record

#### advantages:
insertion is efficient and simple
#### disadvantages
searching inefficient, O(n)
deleting inefficient, search first, then empty space left

### sequential organisation
#### approach
records are stored in sequential order, based on some attribute of the records, usually a primary key
often uses an index
allows records to be read in sorted order
#### advantages
reading records in order is efficient
searching is efficient on key field, O(log n)
easy to find "next" record
#### disadvantages
insertion and deletion expensive
// pointer chain in header often used
search inefficient on non-key field

### hashed file organisation
a hash function is computed on some attribute of each record
the output of this function is the block address where the record should be stored
// common function is mod q, where q is prime
            
criteria for hash function
- easy and quick to compute
- should uniformly distribute the hashed addresses
- should anticipate file growth, so that only a fraction of each block is initially filled

#### issues
hash collisions // TODO: link to [[ct216]]
a workaround for this is **linear probing**
-> if i is a collision, and full, check i+1, i+2 until space found
-> can degrade to a linear scan if load function is high

### database indexing
speeds up operations that are not efficiently handled by basic organisation
consists of index entries
each entry is a key and record/block pointer pair
these index entries are placed in sequential sorted order or hashed order either on the disk, or held in main

#### retrieving a record from an index
1) retrieve index file
2) search for required index key, to obtain desired pointer
3) answer query and return record to storage

#### dense vs sparse indexes
an index is dense if it contains an entry for every record in the file
a sparse index only contains block entries
sparse indexes are sometimes called primary indexes

##### primary indexes
total number of entries = total number of blocks in ordered file
first record in each block is the _anchor record_

###### advantages
fewer entries than a record index, so smaller file
###### disadvantages
insertions and deletions may change the anchor record
searching may take longer

##### clustered and secondary indexes
records that are logically related are physically stored close together on the disk (i.e. in the same block, or consecutively)

records are physically ordered on a non-key field that does not have a distinct value for each record

###### clustering index consists of
- clustrering field value
- block pointer to first block that contains a record in this cluster

###### advantages
quick searching on clustered records
disadvantages
no benefit on non-clustered records

###### secondary index
an index whose clustering value specifies an order that is different to the underlying sequential order of the records

any number of secondary indexes can be built in, and any attribute can be chosen for this reason

![[indexes_0.png]]

#### b-trees
![[b-trees_0.png]]
most commercial systems use an indexing structure called b-trees, or more specifically b+ trees
b+ trees allow as many levels of indexing as is appropriate for the file specified
b-trees manage the space in blocks such that each one is between half and completely full
consist of sequences of pointers arranged in a tree

> #databases 