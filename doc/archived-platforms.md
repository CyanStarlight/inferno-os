# Archived platforms and architectures

This directory collects information and archived code for platform and architecture ports that have been removed from the mainline `inferno-modern` build matrix.

If you need to maintain or restore a port, you can check out the corresponding archived directory under `archived/arch/` and follow the build instructions there.

Archival policy
 - We will keep a complete copy of removed ports under `archived/arch/` (preserving history using `git mv`) so volunteers can maintain them outside the mainline.
 - The mainline repository will retain only actively supported platforms: Linux, MacOSX, Nt (Windows), and FreeBSD.

How to resurrect an archived port
1. Create a branch based on `modern`.
2. Copy files from `archived/arch/<arch>/` into their original locations (or open a PR to re-add the port).
3. Update `mkconfig` and mkfiles to re-enable the OBJTYPE for that port and test on a machine with the proper toolchain.

Why an architecture gets archived
- Minimal usage among contributors and users
- High maintenance cost (toolchain differences, deprecated hardware)
- To reduce time needed for CI and code review

Current archived architectures (this PR): s800 (HP PA‑RISC), sparc, mips & spim, power (PowerPC)

Rough size of archive (lines of code moved from mainline into archive):

- s800 (HP PA‑RISC): ~336 lines (~0.34 kLOC)
- sparc: ~9,508 lines (~9.51 kLOC)
- mips: ~10,642 lines (~10.64 kLOC)
- spim: ~2,274 lines (~2.27 kLOC)
- power (PowerPC): ~11,536 lines (~11.54 kLOC)

Total moved: ~34,296 lines (~34.29 kLOC).

Notes: these counts include architecture-specific C/H/ASM files, mkfiles, and supporting includes. If you want a narrower count that excludes documentation and mkfile fragments, I can recompute a "code-only" sum.

Notes
- Not all archived files are guaranteed to be buildable on a modern host without manual changes — the archive is a snapshot for volunteer maintainers only.
