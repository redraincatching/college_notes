# Web Crawlers


Find content on the web independent of any query
&nbsp&nbsp&nbsp&nbsp→ no central directory, so each engine has created their own database
&nbsp&nbsp&nbsp&nbsp→ these directories are created + updated by spiders/crawlers
&nbsp&nbsp&nbsp&nbspe.g. googlebot, bingbot (microsoft), slurp (yahoo), etc.

(website owners can also submit their pages to be crawled)

When a spider first visits a site, they first find the _robots.txt_ file
&nbsp&nbsp&nbsp&nbsp→ a text file the webamster creates to instruct crawlers on how to crawl their website
&nbsp&nbsp&nbsp&nbsp→ placed in root domain
&nbsp&nbsp&nbsp&nbsp→ only applies to crawlers following _REP_, robot exclusion protocol

---
## Sample Crawler Algorithm
Crawler begins with urls that constitute a "seed set", and adds them to the _frontier set_
&nbsp&nbsp&nbsp&nbsp→ an open list of unvisited nodes in the web graph
&nbsp&nbsp&nbsp&nbsp→ crawler traverses this set according to its selection policy (fifo, priority, etc.)

For the url picked, the crawler:
-   looks up DNS
-   connects to host
-   sends a request
-   receives a request → based on this waits/retries/repeats/proceeds

if proceeding, get robots.txt, then fetch the first portion of the webpage using http protocol
&nbsp&nbsp&nbsp&nbsp→ this has been proven to be "representative enough" of the webpage

fetched portion is written to a temporary store, then parsed.
&nbsp&nbsp&nbsp&nbsp→ checked to see if the webpage already exists/is blacklisted

if source is valid, all meaningful information is fed to a text [[indexing|indexer]]
&nbsp&nbsp&nbsp&nbsp→ extracted links are added to the frontier set

for efficiency, crawling is often **distrubuted**
&nbsp&nbsp&nbsp&nbspa single url server sends urls to multiple crawlers
&nbsp&nbsp&nbsp&nbspeach crawler maintains several simultaneous connections

// a major performance stress is DNS lookup, so to avoid this, each crawler often maintains its own DNS cache

---
### Crawler Behaviour
defined by policies, such as

-   selection policy - defines the order in which the frontier set urls are visited
-   re-visit policy - indicates when to recheck pages
-   politeness policy - to prevent websites from being overloaded with requests
-   parallelisation policy - to coordinate distributed crawlers

> #algorithms 
> [[search_engines]]