# Geeko Store

Native app store application with same function of software.opensuse.org

## Why we make it?

- Get correct package for your system without manually configuration: system
  version, architecture.
- No need to download and parse XML files.
- Offline browsing support.
- Don't depend on software.opensuse.org server.

## Technology

### Package management: Zypper / Libzypp

PackageKit doesn't provide some key features like manage repositories. And it is
not reliable.

AppStream tool also doesn't work well in openSUSE.

Our first version will open a terminal window and execute some zypper commands.
The final version will directly use libzypp.

### Programming language: C++

The application depends on Libzypp, which currently only have C/C++ and Ruby
bindings. (Python binding has been discontinued)

### UI library: Qt 5 and Qt Quick Control 2

With Qt Quick, it is easier to create complex UI.

Qt 5 also has better HiDPI support, native look and feel among all DEs.
