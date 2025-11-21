# Archived platforms and architectures

This directory collects information and archived code for platform and architecture ports that have been removed from the mainline `inferno-modern` build matrix.

This branch permanently removed the historical `archived/` copy of retired ports; the archive is no longer kept in this branch. If you need to maintain or restore a port, check out an older commit or a dedicated archival branch (if present) and follow the build instructions there.

Archival policy
 - Historically we kept removed ports under `archived/arch/` (preserving history using `git mv`); those copies were removed from this branch to simplify the mainline. Volunteers should use the archival branch or commit history for long-term maintenance.
 - The mainline repository will retain only actively supported platforms: Linux, MacOSX, Nt (Windows), and FreeBSD.

How to resurrect an archived port
1. Create a branch based on `modern`.
2. Copy files from the archival branch or commit history into their original locations (or open a PR to re-add the port).
3. Update `mkconfig` and mkfiles to re-enable the OBJTYPE for that port and test on a machine with the proper toolchain.

Why an architecture gets archived
- Minimal usage among contributors and users
- High maintenance cost (toolchain differences, deprecated hardware)
- To reduce time needed for CI and code review


Notes
- Not all archived files are guaranteed to be buildable on a modern host without manual changes — the archive is a snapshot for volunteer maintainers only.
