# RuntimeVDB

RuntimeVDB is an Unreal Engine plugin, available on Fab / Marketplace.

<img width="1920" height="1080" alt="Viewer_HD_01" src="https://github.com/user-attachments/assets/de7a352b-f20c-4197-a7ed-78e58c01c3b9" />

## Introduction

RuntimeVDB is an **experimental** plugin that asynchronously imports, caches, and streams OpenVDB files at runtime, and renders them using Unreal Engine’s native Heterogeneous Volume component. All core functionality is exposed to Blueprints, enabling precise setup in the Editor and full runtime control.

RuntimeVDB is primarily intended for industrial and scientific data visualization rather than game development.

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
 
## Development Status
As this plugin is experimental, development is ongoing and improvements will continue until it reaches Beta status. Constructive feedback, bug reports, comments, and suggestions are welcome. Please use [Issues](https://github.com/thilamb/RuntimeVDB-Fab/issues) to reach out.


## My other plugins
* [VDB / SVT Helper](https://www.fab.com/listings/2cc1bd5a-40df-49a2-bd52-42fa06b114dc), available on Fab / Marketplace
* [Unreal-VDB](https://github.com/thilamb/unreal-vdb), a NanoVDB code plugin
