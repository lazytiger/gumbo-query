class GumboQuery < Formula
  homepage "https://github.com/Falven/gumbo-query"
  url "https://github.com/Falven/gumbo-query.git", :using => :git
  sha256 "e772da6f700b29367d4ab7a7d462d89c0a6fff0e238c725eda8d9d7c44025839"

  depends_on "autoconf" => :build
  depends_on "automake" => :build
  depends_on "libtool" => :build

  def install
    system "./autogen.sh"
    system "./configure", "--disable-debug",
                          "--disable-dependency-tracking",
                          "--disable-silent-rules",
                          "--prefix=#{prefix}"
    system "make", "install"
  end
end