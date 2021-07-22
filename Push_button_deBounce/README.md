# Push button debouncer

During my eletronics/programming studies I came up with algorithms to debounce push buttons, so you're going to find here my solutions to solve this inherent problem of switches.

My first algorithm used delay(), but this is not a very neat solution, specially when the processor needs to deal with multiple operations simultaneously. With that said, I was introduced with state machine and started using millis() instead of delay(). Then I realized I could use counters by themselfs, but depending on the load on the processor they need to be optimized so the button is responsive.

At last, after searching for other solutions, I came across with this document here listed as debouncing.pdf, made by Jack G. Ganssle. There he lists a very elegant way to debounce switches and I addapted it to my algorithm named By_counter_and_time.ino.