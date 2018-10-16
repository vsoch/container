# Container

What is a container? It seems like a fairly simple question... if you are talking
about tupperware. In the case of computers, it's a bit more complicated than that.
Some might call it some kind of 
[operating system virtualization](https://en.wikipedia.org/wiki/Operating-system-level_virtualization). But on the other
hand, *true* virtualization is more properly understood to be emulating something
on the hardware level, which a container is not. We recently had much discussion
on this issue, and ultimately (sort of) agreed on one idea:

 > A container is a kind of isolation technology that can employ virtualization (but doesn't have to). In this context, Virtualization is more of an attribute instead.

No promises that this statement is still true. But actually, I don't want to go into
this delicate argument about whether a Container is a kind of Virtualization (or not).
Instead, I want to learn things one of the best ways I know how. By building from
scratch. Even if I can't (on the level of ontology) best define the idea of container,
I will have better intuition for containers if I can make one from scratch.
So that's what we are doing here, following [this guide](http://cesarvr.github.io/post/2018-05-22-create-containers)
and then going from there.
