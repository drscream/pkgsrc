package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Lines_CheckRcsID(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("filename",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for i := range lines.Lines {
		lines.CheckRcsID(i, ``, "")
	}

	t.CheckOutputLines(
		"ERROR: filename:3: Expected \"$"+"NetBSD$\".",
		"ERROR: filename:4: Expected \"$"+"NetBSD$\".",
		"ERROR: filename:5: Expected \"$"+"NetBSD$\".")
}

// Since pkgsrc-wip uses Git as version control system, the CVS-specific
// IDs don't make sense there. More often than not, the expanded form
// "$NetBSD:" is a copy-and-paste mistake rather than an intentional
// documentation of the file's history. Therefore, pkgsrc-wip files should
// only use the unexpanded form.
func (s *Suite) Test_Lines_CheckRcsID__wip(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupPackage("wip/package",
		"CATEGORIES=\tchinese")
	t.CreateFileLines("wip/package/file1.mk",
		"# $"+"NetBSD: dummy $")
	t.CreateFileLines("wip/package/file2.mk",
		"# $"+"NetBSD$")
	t.CreateFileLines("wip/package/file3.mk",
		"# $"+"Id: dummy $")
	t.CreateFileLines("wip/package/file4.mk",
		"# $"+"Id$")
	t.CreateFileLines("wip/package/file5.mk",
		"# $"+"FreeBSD$")

	G.CheckDirent(t.File("wip/package"))

	t.CheckOutputLines(
		"NOTE: ~/wip/package/file1.mk:1: Expected exactly \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file3.mk:1: Expected \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file4.mk:1: Expected \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file5.mk:1: Expected \"# $"+"NetBSD$\".")

	G.Logger.Opts.Autofix = true

	G.CheckDirent(t.File("wip/package"))

	t.CheckOutputLines(
		"AUTOFIX: ~/wip/package/file1.mk:1: Replacing \"# $NetBSD: lines_test.go,v 1.2 2018/12/02 23:12:43 rillig Exp $\" with \"# $NetBSD: lines_test.go,v 1.2 2018/12/02 23:12:43 rillig Exp $\".",
		"AUTOFIX: ~/wip/package/file3.mk:1: Inserting a line \"# $NetBSD: lines_test.go,v 1.2 2018/12/02 23:12:43 rillig Exp $\" before this line.",
		"AUTOFIX: ~/wip/package/file4.mk:1: Inserting a line \"# $NetBSD: lines_test.go,v 1.2 2018/12/02 23:12:43 rillig Exp $\" before this line.",
		"AUTOFIX: ~/wip/package/file5.mk:1: Inserting a line \"# $NetBSD: lines_test.go,v 1.2 2018/12/02 23:12:43 rillig Exp $\" before this line.")
}
