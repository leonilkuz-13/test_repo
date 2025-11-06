from code.main import Calc
from contextlib import nullcontext as does_not_raise

import pytest


@pytest.mark.usefixtures

class TestCalc:
    @pytest.mark.parametrize(
        "x,y,res,expectation",
        [(1, "2", 0.5, pytest.raises(TypeError)), ("4", 2, 2, pytest.raises(TypeError)), (6, 3, 2.0, does_not_raise())],
    )
    def test_divide(self, x, y, res, expectation):
        with expectation:
            assert Calc().divide(x, y) == float(res)

    @pytest.mark.parametrize("x, y, res", [(1, 2, 3), (4, 2, 6), (5, 3, 8)])
    def test_add(self, x, y, res,expectation):
        with expectation:
            assert Calc().add(x, y) == res
