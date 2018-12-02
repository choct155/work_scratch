# History Object

A history object is meant to store changes of state in an attribute over time.  For example, a person may move their residence to different locations over time. The history object should be able to return their residence at any given time. This can be done inefficiently via a comprehensive map of all times to locations at that time. However, the history object seeks a more space efficient solution that needs only the minimum information needed to define the range (the starting and ending time periods).

## Requirements

1. If a user requests state at a time that is before all other known times in the history object, the object should return Nothing.
2. The history object should assume that the last change holds until the current time, so there is no time that falls after the time covered by the tree. If a user queries the current time, the last known state should be returned.
3. The relevant interval for a state should extend from the time at which the new state value was realized (inclusive) until the time at which the next state value is realized (exclusive)
4. If a user requests state at a valid time (as in covered by the range in the object), the history object should return state for the interval in which the time is located.
5. A given state value should be able to appear in more than one range, so long as they are discontinuous. (Continuous ranges should be consolidated into a single range.)


