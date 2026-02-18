# Changelog

All notable changes for this repository.

## Unreleased / 2026-02-18

- Refactor: split large functions and reorganized helpers so every source now respects Norm rules (functions ≤ 25 lines, tabs-only, aligned declarations).
- Files added / renamed: `ft_fill_matrix.c`, `ft_free_map.c`, `ft_mark_square.c`, `ft_memory.c`, `ft_parse_header.c`, `ft_print_map.c`, `ft_string.c`.
- Tests: added missing fixtures (total `test_maps/` = **35**). Stress tests included: `test15_large.txt` (100×100) and `test16_very_large.txt` (500×500).
- Fixes: resolved parsing/implicit-declaration compile errors, fixed off-by-one and memory leaks (valgrind-clean).
- Docs: updated `README.md`, `bsq/QUICK_REFERENCE.md`, `bsq/TEST_DOCUMENTATION.md`, `bsq/DEBUG_GUIDE.md`, `bsq/BSQ_COMPLETE_PACKAGE.md`.
- Metadata: prepared commit with Co‑authored‑by: Mina Zahir <mina-zahir@users.noreply.github.com>.

---

*All changes are covered by the test suite — current status: **35/35** passing.*
