class GumboQuery < Formula
  homepage "https://github.com/lazytiger/gumbo-query"
  head "https://github.com/lazytiger/gumbo-query.git"

  depends_on "cmake" => :build

  def install
    mkdir "build" do
      args = std_cmake_args
      system "cmake", "..", *args
      system "make"
      system "make", "install"
    end
  end

  def test
    system "make test"
  end
end
