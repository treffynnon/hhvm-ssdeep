ssdeep Extension for HipHop (HHVM)
==================================

This is an implementation of the `ssdeep` PHP extension for the [HipHop PHP VM][fb-hphp].

## Prerequisites

This extension only requires the `libfuzzy` library distributed with ssdeep and the HipHop VM (HHVM) itself.

### libfuzzy installation

This can be done either from the [ssdeep source](http://ssdeep.sourceforge.net/) or from your systems packages. On Ubuntu you'll need to install [`libfuzzy-dev`](http://packages.ubuntu.com/search?keywords=libfuzzy-dev).

## Building and installation

Installation requires a copy of HipHop to be **built from source** on the local machine, instructions
on how to do this are available on the [HipHop Wiki][fb-wiki]. Once done, the following commands
will build the extension.

Firstly, ensure that the `$HPHP_HOME` env var has been set:

~~~
export HPHP_HOME=/path/to/hhvm
~~~~

Then the build proper:

~~~
$ cd /path/to/extension
$ $HPHP_HOME/hphp/tools/hphpize/hphpize
$ cmake .
$ make
~~~

This will produce a `ssdeep.so` file, the dynamically-loadable extension.

To enable the extension, you need to have the following section in your hhvm config file (typically config.hdf):

~~~
DynamicExtensionPath = /path/to/hhvm/extensions
DynamicExtensions {
	* = ssdeep.so
}
~~~

Where `/path/to/hhvm/extensions` is a folder containing all HipHop extensions, and `sdeep.so` is in
it. This will cause the extension to be loaded when the virtual machine starts up.

## Documentation

This extension is functionally equivalent to the PECL version I also maintain so the same documentation is applicable - see [php.net/ssdeep](http://php.net/ssdeep).

### Differences from PECL

There is one difference from the standard PECL implementation.

* The info function is not included as HipHop VM does not implement phpinfo(); - //this does not affect the extensions public API//

Otherwise, all functionality is (or should be) the same as the PECL implementation.

As always, bugs should be reported to the issue tracker and patches are very welcome.

[fb-hphp]: https://github.com/facebook/hhvm "HipHop PHP"
[fb-wiki]: https://github.com/facebook/hhvm/wiki "HipHop Wiki"
