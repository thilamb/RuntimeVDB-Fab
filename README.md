# RuntimeVDB

RuntimeVDB is an Unreal Engine plugin, [available on Fab / Marketplace](https://www.fab.com/listings/12fd5458-5d7f-4123-8614-138a689c030b).

<img width="1920" height="1080" alt="Viewer_HD_01" src="https://github.com/user-attachments/assets/de7a352b-f20c-4197-a7ed-78e58c01c3b9" />

## Introduction

RuntimeVDB is an C++ plugin that asynchronously imports, caches, and streams OpenVDB files at runtime, and renders them using Unreal Engine’s native Heterogeneous Volume component. All core functionality is exposed through both Blueprint and C++ APIs, enabling precise Editor setup and seamless integration into code-driven runtime workflows.

RuntimeVDB is primarily intended for industrial and scientific data visualization.

## Features
* Imports, caches, streams, and displays OpenVDB files at runtime only
* Supports both Static and Animated (Sequence) OpenVDB files
* Asynchronous background loading (runtime only, non-blocking)
* Works in the Editor for setup and configuration; actual VDB import occurs only while the application is running (Play In Editor or packaged build)
* Includes 3 example levels and 7 Blueprint templates demonstrating common runtime workflows
* Same runtime performance as native SVTs and Heterogeneous Volumes

> [!WARNING]
> Rendering relies entirely on Unreal Engine’s native Heterogeneous Volume system. The plugin does not modify VDB shading and rendering.

 <img width="1920" height="1080" alt="BlueprintFunctions" src="https://github.com/user-attachments/assets/620b492c-aef5-4360-af62-83a31a48190f" />

## For Programmers
As a native C++ plugin, all functionality is fully accessible through C++ APIs. While there are multiple ways to load OpenVDB files from code, you can find two example source files demonstrating asynchronous VDB loading using custom lambda callbacks:

https://github.com/thilamb/RuntimeVDB-Fab/blob/main/MyActor.h

https://github.com/thilamb/RuntimeVDB-Fab/blob/main/MyActor.cpp
 
## Development Status
Constructive feedback, bug reports, comments, and suggestions are welcome. Please use [Issues](https://github.com/thilamb/RuntimeVDB-Fab/issues) to reach out.


## My other plugins
* [VDB / SVT Helper](https://www.fab.com/listings/2cc1bd5a-40df-49a2-bd52-42fa06b114dc), available on Fab / Marketplace
* [Unreal-VDB](https://github.com/thilamb/unreal-vdb), a NanoVDB code plugin
