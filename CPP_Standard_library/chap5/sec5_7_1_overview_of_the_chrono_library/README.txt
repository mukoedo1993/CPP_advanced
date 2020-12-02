A duration of time is defined as a specific number of ticks over a time unit. One example is a duration such as "3 minutes" (3 ticks of a minute) Others examples
are "42 milliseconds" or "86400 seconds", which represents the duration of 1 day. The concept also allows specifying sth like "1.5 times a third of a second", where
1.5 is the No. of ticks and "a third of a second," where 1.5 is the number of ticks and a third of a second" the time unit used.

A timepoint is defined as combination of a duration and a beginning of time (the so-called epoch). A typical example is a timepoint that represents "New Year's Midnight
2000," which is described as "1262300400 seconds since January 1, 1970" (this day is the epoch of the system clock of UNIX and POSIX systems)

The concept of a timepoint, however, is parameterized by a clock, which is the object that defines the epoch of a timepoint. Thus, different clocks have different epochs.
In general, operations dealing with multiple timepoints, such as processing the duration/difference between two time-points, require using the same epoch/closk. A clock
also provides a convenience function to yield the timepoint of now.
