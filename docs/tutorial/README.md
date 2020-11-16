# Getting started

* [Harbour programming language](https://en.wikipedia.org/wiki/Harbour_(programming_language))
* [Homepage](https://harbour.github.io)
* Select your Harbour:
   - [hb30](https://sourceforge.net/projects/harbour-project/files/)
   - [hb32](https://github.com/harbour/core)
   - [hb34](https://github.com/vszakats/harbour-core)

# Install Cairo

### ![MSYS2](../assets/img/msys2.png) MSYS2

```

pacman -S mingw-w64-x86_64-cairo

```

```

export HB_WITH_CAIRO="$usr/mingw64/include"

```

### ![mingw-w64](../assets/img/mingw-w64.png) mingw-w64

Download binaries **Cairo** from this project and install:

```

c:\cairo\bin
c:\cairo\include
c:\cairo\lib

```

Install the rest of the missing libraries in mingw-w64

```

c:\>mingw-w64

```

Click New to create a new environment variable. Click Edit to modify an existing environment variable.

![Advanced System Settings in Windows 10](../assets/img/hb-cairo_01.png "Advanced System Settings in Windows 10")

After creating or modifying the environment variable, click OK to have the change take effect.

The Edit environment variable UI will appear. Here, you can click New and type in the new path you want to add. From this screen you can also edit or reorder them.

![Advanced System Settings in Windows 10](../assets/img/hb-cairo_02.png "Advanced System Settings in Windows 10")

> Note: The graphical user interface for creating environment variables may vary slightly, depending on your version of Windows.

For the record:

```

c:\>set HB_WITH_CAIRO=C:\cairo\include
c:\>set PATH=C:\cairo\bin;%PATH%

```

##

[Edit me](https://github.com/rjopek/hb-cairo/edit/main/docs/tutorial/README.md)
